name_mapping = {"--edit-caching false --query-caching false": "NOCache",
                "--query-cache-type RCC_MEM_LIT": "RCCLIT",
                '--query-cache-type CONTENT_SHA512': "SHA512",
                '--query-cache-type CONTENT_ZIP': "ZIP",
                '--query-cache-type ORIG_CONTENT_STRING_BASED': "STR",
                '--query-cache-type COMPACT_QUERY_CACHE': "RCC",
                '--query-cache-type COMPACT_QUERY_CACHE_FORMAT_SENSITIVE --code-format COMPACT_ORIG_FORMAT --query-caching TRUE': 'RCCFORMAT',
                '--query-cache-type CONTENT_SHA512_FORMAT --code-format COMPACT_ORIG_FORMAT --query-caching TRUE': 'SHAFORMAT'
                }