
import pdb
import os
from collections import defaultdict


def get_module(key):
    return key.split('(')[-2].split()[-1].split('::')[1] #manipulate namespace syntax

log_dir = os.path.join(os.environ['APOLLO_ROOT_DIR'], 'data', 'log')
module_log_count = defaultdict(int)
module_unique_logs = dict()
module_functions = defaultdict(list)
for file in os.listdir(log_dir):
    if os.path.islink(os.path.join(log_dir, file)):
        continue
    else:
        with open(os.path.join(log_dir, file)) as f:
            coverage_statements = filter(lambda x: "[COV_LOG]" in x, f.readlines())
            for call, func in [token.split(" [COV_LOG] ") for token in coverage_statements]:
                if func.rstrip('\n') not in module_unique_logs:
                    module_unique_logs[func.rstrip('\n')] = 1
                    module_log_count[get_module(func)] += 1
                    module_functions[get_module(func)].append(func.rstrip('\n'))
                else:
                    module_unique_logs[func.rstrip('\n')] += 1

for key, count in module_log_count.items():
    print(key, ":", count)
print()
for key, item in module_unique_logs.items():
    print(key, ":", item)
print()
for key, item in module_functions.items():
    print(key, ":", item)