
import pdb
import json
import os
from collections import defaultdict
import sys

experiment = sys.argv[1]

def get_module(key):
    try:
        namespace = key.split('(')[-2].split()[-1].split('::')[1] #manipulate namespace syntax
        if '<lambda' in namespace:
            try:
                namespace = key.split('(')[-3].split()[-1].split('::')[1]
            except:
                print("Exception:", namespace)
    except:
        namespace = 'planning'
    return namespace
log_dir = os.path.join(os.environ['APOLLO_ROOT_DIR'], 'data', 'log', experiment)
module_log_count = defaultdict(int)
module_unique_logs = dict()
module_functions = defaultdict(list)

count = len(os.listdir(log_dir))

i = 0
print(count, "files to process.")
for file in os.listdir(log_dir):
    if i % int(count / 20) == 0:
        print("Percent:", i/int(count)) 
    if os.path.islink(os.path.join(log_dir, file)):
        continue
    else:
        try:
            with open(os.path.join(log_dir, file)) as f:
                coverage_statements = filter(lambda x: "[COV_LOG]" in x, f.readlines())
                for call, func in [token.split(" [COV_LOG] ") for token in coverage_statements]:
                    if func.rstrip('\n') not in module_unique_logs:
                        module_log_count[get_module(func)] += 1
                        module_unique_logs[func.rstrip('\n')] = 1
                        module_functions[get_module(func)].append(func.rstrip('\n'))
                    else:
                        module_unique_logs[func.rstrip('\n')] += 1
            i += 1
        except Exception as e:
            print("Exception:", e)

try:
    print(f"Processed {count} files.")
    json_output = {
        'total_count_analyzed': count,
        'unique_entry_point_per_namespace': module_log_count,
        'method_in_namespace': module_functions,
        'unique_call_to_each_method': module_unique_logs
    }

    with open(os.path.join(os.environ['APOLLO_ROOT_DIR'], 'data', 'log', f"{experiment}_analysis.json"), "w") as f:
        json.dump(json_output, f)
    print("Dumped to file.")
except:
    pdb.set_trace()
    print(json_output)