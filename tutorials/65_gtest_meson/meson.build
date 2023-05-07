project('Google test with meson', 'cpp')

gtest_proj = subproject('gtest')
gtest_dep = gtest_proj.get_variable('gtest_main_dep')
gmock_dep = gtest_proj.get_variable('gmock_dep')

app_src = files('my_code.cpp')  

tests_src = files('my_test.cpp')  

e = executable(
  'gtest',
  tests_src + app_src,
  dependencies : [
    gtest_dep,
    gmock_dep]
)    
test('gtest', e)