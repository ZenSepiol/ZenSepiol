project('random_pi', 'cpp')

incdir = include_directories('/home/zen/imgui/', '/home/zen/imgui/backends', './implot')

glfw_lib = subproject('glfw').get_variable('glfw_dep')
gl = dependency('gl')

files = files(
    'main.cpp', 
    '/home/zen/imgui/imgui.cpp',
    '/home/zen/imgui/imgui_draw.cpp',
    '/home/zen/imgui/imgui_tables.cpp',
    '/home/zen/imgui/imgui_demo.cpp',
    '/home/zen/imgui/imgui_widgets.cpp',
    '/home/zen/imgui/backends/imgui_impl_glfw.cpp', 
    '/home/zen/imgui/backends/imgui_impl_opengl3.cpp', 
    './implot/implot.cpp', 
    './implot/implot_items.cpp'
)

executable('random_pi', files, include_directories : incdir, dependencies : [glfw_lib, gl] )