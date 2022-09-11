
limiter_files = files(
    'limiter.cpp',
    'limiter_test.cpp'
)

limiter_test = executable('limiter_test', limiter_files, include_directories : incdir, dependencies : [catch_lib])
test('limiter_test', limiter_test)