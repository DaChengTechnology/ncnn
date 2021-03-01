Pod::Spec.new do |spec|

  spec.name         = "NCNN_MAC"
  spec.version      = "20210301"
  spec.summary      = "ncnn powerby Tencent."

  spec.description  = <<-DESC
  ncnn is a high-performance neural network inference framework optimized for the mobile platform.
    DESC

  spec.homepage     = "https://github.com/Tencent/ncnn"

  spec.license      = { :type => "BSD 3-Clause", :file => "https://github.com/Tencent/ncnn/LICENSE.txt" }

  spec.author             = { "DCTech" => "412200533@qq.com" }

  spec.platform     = :osx, "10.15"

  spec.source       = { :http => "https://github.com/DaChengTechnology/ncnn/releases/download/20210301/ncnn-20210301-macos-vulkan-pod.zip"}

  spec.vendored_libraries = "**/**/libglslang.a","**/**/libncnn.a","**/**/libOGLCompiler.a","**/**/libomp.a","**/**/libOSDependent.a","**/**/libSPIRV.a"

  spec.xcconfig = { 'HEADER_SEARCH_PATHS' => '**/mac/Include'}
  }

end
