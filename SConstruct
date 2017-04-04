

link_flags = []
compile_flags = ['-g', '-ggdb'] 
build_d='build'

shared_sources = ['libsample.c']

env = Environment(
  CCFLAGS=compile_flags,
  LINKFLAGS=link_flags
)

env.SharedLibrary('libsample.so',
  source=shared_sources,
  variant_dir=build_d,
)

env.Program('run.o',
  source=[
    'main.c'
  ],
  LIBS=['dl']
)

