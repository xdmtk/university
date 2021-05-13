flags = [
    '-Wall',
    '-Wextra',
    '-Werror',
    '-Wno-long-long',
    '-Wno-variadic-macros',
    '-fexceptions',
    '-DNDEBUG',
    '-x', #I don't know if I need remove -x
    'c',
    '-I./usr/include',
    '-I./usr/local/include',
    '-I../../include'
]

def FlagsForFile(filename):
    return {'flags' : flags }
