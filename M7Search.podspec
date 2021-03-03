Pod::Spec.new do |s|
    s.name         = 'M7Search'
    s.version      = '1.0.0'
    s.summary      = 'An elegant search controller which replaces the UISearchController for iOS.'
    s.homepage     = 'https://github.com/DeveloperMan7/M7Search'
    s.license      = 'MIT'
    s.authors      = {'Man7' => '0x00hl7@gmail.com'}
    s.platform     = :ios, '11.0'
    s.source       = {:git => 'https://github.com/DeveloperMan7/M7Search.git', :tag => s.version}
    s.source_files = 'M7Search/**/*.{h,m}'
    s.resource     = 'M7Search/M7Search.bundle'
    s.requires_arc = true
end


