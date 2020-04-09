Pod::Spec.new do |spec|
  spec.name         = 'MapNavigationKit'
  spec.version      = '1.0'
  spec.license      = 'MIT'
  spec.homepage     = 'https://github.com/username0x0a/MapNavigationKit'
  spec.authors      = 'Michal Zelinka'
  spec.summary      = 'Advanced routing info built on top of MapKit'
  spec.source       = { :http => 'https://github.com/username0x0a/MapNavigationKit/releases/download/v1.0/MapNavigationKit-1.0.zip' }
  spec.module_name  = 'MapNavigationKit'

  spec.osx.deployment_target  = '10.10'
  spec.ios.deployment_target  = '10.0'

  spec.framework      = 'MapKit'

  spec.osx.vendored_frameworks = 'Mac/MapNavigationKit.framework'
  spec.ios.vendored_frameworks = 'iOS/MapNavigationKit.framework'
end
