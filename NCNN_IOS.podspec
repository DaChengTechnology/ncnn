Pod::Spec.new do |spec|

  spec.name         = "NCNN_IOS"
  spec.version      = "20210301"
  spec.summary      = "ncnn powerby Tencent"

  spec.description  = <<-DESC
  ncnn is a high-performance neural network inference framework optimized for the mobile platform.
                   DESC

  spec.homepage     = "https://github.com/Tencent/ncnn"

  spec.license      = { :type => "BSD 3-Clause", :file => "https://github.com/Tencent/ncnn/LICENSE.txt" }

  spec.author             = { "DCTech" => "412200533@qq.com" }

  spec.platform     = :ios, "9.0"
  spec.source       = { :http=> "https://github.com/DaChengTechnology/ncnn/releases/download/20210301/ncnn-20210301-ios-vulkan-bitcode-pod.zip" }

  spec.vendored_libraries = "**/Lib/libglslang.a","**/Lib/libncnn.a","**/Lib/libOGLCompiler.a","**/Lib/libomp.a","**/Lib/libOSDependent.a","**/Lib/libSPIRV.a"

  spec.xcconfig = { 'HEADER_SEARCH_PATHS' => '**/Lib/Include'}

  spec.pod_target_xcconfig = {
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
  }
  spec.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }

end
