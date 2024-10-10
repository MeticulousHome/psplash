project('psplash',
 'c',
  version: '1.0',
  default_options: ['warning_level=3', 'buildtype=debugoptimized'],
)

c_args = '''
  -Wbad-function-cast
  -Wcast-align
  -Wdeclaration-after-statement
  -Wformat=2
  -Wshadow
  -Wno-unused-parameter
  -Wno-missing-field-initializers
'''.split()
add_project_arguments(c_args, language : 'c')

# Dependencies
systemd_dep = dependency('systemd', required : get_option('systemd'))
libsystemd_dep = dependency('libsystemd', required : get_option('systemd'))

if systemd_dep.found() and libsystemd_dep.found()
  add_global_arguments('-DHAVE_SYSTEMD', language : 'c')

  systemdsystemunitdir = get_option('systemdsystemunitdir')
  if systemdsystemunitdir == ''
    systemdsystemunitdir = systemd_dep.get_pkgconfig_variable('systemdsystemunitdir')
  endif
  install_data('systemd/psplash-start.service', install_dir : systemdsystemunitdir)
  install_data('systemd/psplash-systemd.service', install_dir : systemdsystemunitdir)
endif

logo_image = custom_target('logo-image-header',
  output : 'psplash-logo-img.h',
  input : 'base-images/psplash-logo.png',
  command : ['bash', meson.current_source_dir() / './make-image-header.sh', '@INPUT@', 'LOGO'],
  install : false
)

# Source files
psplash_sources = files(
  'psplash.c',
  'psplash-fb.c',
  'psplash-console.c',
) + logo_image

# psplash executable
executable('psplash',
  psplash_sources,
  install: true,
  c_args: ['-DFONT_HEADER=' + '"radeon-font.h"','-DFONT_DEF=radeon_font'],
  dependencies: libsystemd_dep
)

# psplash-write
psplash_write = executable('psplash-write',
  'psplash-write.c',
  install: true,
)

if systemd_dep.found()
  # psplash-systemd
  psplash_systemd = executable('psplash-systemd',
    'psplash-systemd.c',
    install: true,
    dependencies: libsystemd_dep
  )
endif