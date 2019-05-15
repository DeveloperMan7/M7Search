Pod::Spec.new do |s|
    s.name         = 'M7Search'
    s.version      = '0.9.1'
    s.summary      = 'An elegant search controller which replaces the UISearchController for iOS.'
    s.homepage     = 'https://github.com/DeveloperMan7/M7Search'
    s.license      = 'MIT'
    s.authors      = {'CoderKo1o' => '361208971@qq.com'}
    s.platform     = :ios, '7.0'
    s.source       = {:git => 'https://github.com/DeveloperMan7/M7Search.git', :tag => s.version}
    s.source_files = 'M7Search/**/*.{h,m}'
    s.resource     = 'M7Search/M7Search.bundle'
    s.requires_arc = true
end


