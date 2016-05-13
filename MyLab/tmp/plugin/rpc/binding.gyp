{
  'targets': [
     {
         'target_name': 'rpc',
         'sources': [
              'ProtoTrans.cpp',
              'RouterExport.cpp',
              'RouterProcessorExport.cpp',
              'RpcAddon.cpp',
              'RpcExport.cpp',
              'RpcProcessorExport.cpp',
              'ServiceExport.cpp'
          ],
                   
          'include_dirs': [ 
              '../../Common/Include',
              '../../deps/boost/include'
          ],
          
          'conditions': [
              [ 'OS=="win"', {
                  "link_settings": {
                      'libraries': [
                          '-llibprotobuf.lib',
                          '-lwinhiredis.lib'
                      ]
                  },
                  'configurations': {
                      'Debug': {
                          'msvs_settings': {
                              'VCLinkerTool': {
                                  'AdditionalLibraryDirectories': [
                                      '../../../deps/lib/redis/lib_win',
                                      '../../../deps/lib/protobuf/lib_win',
                                      '../../../deps/lib/boost/lib_win'
                                  ]
                              },
                              'VCCLCompilerTool': {
                                  'AdditionalOptions': [
                                      '/MDd',
                                      '/EHsc'
                                  ],
                                  'RuntimeTypeInfo': 'true'
                              }
                          }
                      },
                      'Release': {
                           'msvs_settings': {
                              'VCLinkerTool': {
                                  'AdditionalLibraryDirectories': [
                                      '../../../deps/lib/redis/lib_win',
                                      '../../../deps/lib/protobuf/lib_win',
                                      '../../../deps/lib/boost/lib_win'
                                  ]
                              },
                              'VCCLCompilerTool': {
                                  'AdditionalOptions': [
                                      '/MDd',
                                      '/EHsc'
                                  ],
                                  'RuntimeTypeInfo': 'true'
                              }
                          }

                      }
                  }
              }],
              
              ['OS=="linux"', {
                  'libraries': [
                       '-L../../../Common/linux64',
                       '-L../../../deps/boost/lib',
                       '-L../../../deps/nodejs/v0.10.33/lib',
                       '-Wl,-dn',
                       '-lClusterRouter',
                       '-lboost_log',
                       '-lboost_filesystem',
                       '-lboost_system',
                       '-lboost_thread',
                       '-lboost_date_time',
                       '-lboost_chrono',
                       '-lhiredis',
                       '-lprotobuf',
                       '-lcares',
                       '-lchrome_zlib',
                       '-lhttp_parser',
                       '-lopenssl',
                       '-luv',
                       '-lv8_base',
                       '-lv8_nosnapshot',
                       '-lv8_snapshot',
                       '-Wl,-dy',
                       '-lpthread',
                       '-lrt',
                       '-ldl'
                  ],
                  
                  "cflags!": [ "-fno-exceptions" ],
                  "cflags": [ "-std=c++11", "-fPIC" ],
                  "cflags_cc!": [ "-fno-exceptions", "-fno-rtti" ]
              }]
          ]
      }
   ]
}
