import shutil
import pdb
start_token_file = "<DSTART-FILE>"
start_token_content = "<DSTART-CONT>"
#end_token = "<DEND>"


def get_files_cyber():
    with open('cpp_file_list_wo_test.txt', 'r') as f:
        files = [d[:-1] for d in f.readlines()]
        return files


def create_concat_cyber():
    files = get_files_cyber()
    with open('all_module_cpp_files_concat_cyber.cc','w') as wfd:
        for f in files:
            with open(f, 'r') as fd:
                wfd.write(f)
                shutil.copyfileobj(fd, wfd)

def get_files():
    with open('cpp_modules_list_wo_test.txt', 'r') as f:
        files = [d[:-1] for d in f.readlines()]
        return files


def create_concat():
    files = get_files()
    with open('all_module_cpp_files_concat.cc','w') as wfd:
        for f in files:
            with open(f, 'r') as fd:
                wfd.write(start_token_file)
                wfd.write(f)
                wfd.write(start_token_content)
                shutil.copyfileobj(fd, wfd)

def add_logging():
    with open('symbol_list.txt', 'r') as fl:
        function_filter = filter(lambda i: i.startswith('function'), [l.strip('\t').strip('\n') for l in fl.readlines()])
        function_list = [f[:f.find('(')].lstrip('function ').rstrip('*') for f in function_filter]
        print(len(function_list), " functions in total")
    percent = int(len(function_list) / 100)
    with open('all_module_cpp_files_concat.cc','r') as wfd:
        full_text = wfd.read()
        replace_start = 0
        for i, func in enumerate(function_list):
            search_start = full_text.find(func, replace_start)
            if search_start == -1:
                search_start = full_text.find(func)
                if search_start == -1:
                    print("Cannot find:", func)
                    continue
            replace_start = full_text.find('{', search_start) + 1
            full_text = full_text[:replace_start] + '\nCOVERAGE_LOG_TOKEN\n' + full_text[replace_start:]
    with open('all_module_cpp_files_concat_logged.cc','w') as wfd:
        wfd.write(full_text)

def read():
    files = get_files()
    print()
    with open('all_module_cpp_files_concat_logged.cc','r') as wfd:
        file_contents = wfd.read().split(start_token_file)[1:]
        for i, fc in enumerate(file_contents):
            if i % 60 == 0:
                print("%5 gone")
            f, c = fc.split(start_token_content)
            with open(f, 'w') as fd:
                fd.write('#include "modules/covlogger.h"\n' + c)

'''
Read symbols, find those with function, find the next {, replace it with { + logging
'''
add_logging()
read()

#create_concat_cyber()