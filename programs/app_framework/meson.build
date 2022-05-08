project('Dear ImGui', 'cpp')

incdir = include_directories('/home/zen/imgui/backends', '/home/zen/imgui')

glfw_lib = subproject('glfw').get_variable('glfw_dep')
gl = dependency('gl')



files = files(
    'opengl_glfw_example.cpp',
    '/home/zen/imgui/imgui.cpp',
    '/home/zen/imgui/imgui_draw.cpp',
    '/home/zen/imgui/imgui_tables.cpp',
    '/home/zen/imgui/imgui_demo.cpp',
    '/home/zen/imgui/imgui_widgets.cpp',
    '/home/zen/imgui/backends/imgui_impl_glfw.cpp', 
    '/home/zen/imgui/backends/imgui_impl_opengl3.cpp', 
)

executable('example', files, include_directories : incdir, dependencies : [glfw_lib, gl] )




files = files(
    'main.cpp',
    '/home/zen/imgui/imgui.cpp',
    '/home/zen/imgui/imgui_draw.cpp',
    '/home/zen/imgui/imgui_tables.cpp',
    '/home/zen/imgui/imgui_demo.cpp',
    '/home/zen/imgui/imgui_widgets.cpp',
    '/home/zen/imgui/backends/imgui_impl_glfw.cpp', 
    '/home/zen/imgui/backends/imgui_impl_opengl3.cpp', 
)

executable('app_framework', files, include_directories : incdir, dependencies : [glfw_lib, gl] )