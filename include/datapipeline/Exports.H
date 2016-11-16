#ifndef DATAPIPELINE_Exports_H
#define DATAPIPELINE_Exports_H

// Windows dll fix fill
// this file is primarily made to resolve dll issues while building on windows
// mainly just prefix EXPORTS pragma with class names
#ifdef _MSC_VER
    // disable warnings
    #pragma warning(disable:4996)
    // disable private members in dll export warnings
    #pragma warning(disable:4251)
    #if defined(BUILD_SHARED_LIB)
        #define EXPORTS __declspec(dllexport)
        #define SEXPORTS 1
    #else
		#define EXPORTS __declspec(dllimport)
        #define SEXPORTS 2
    #endif
    
    #define SKIP_DLL
    #define EXPORT_DLL
#else
    #define EXPORTS // Unix like systems including Mac
    #define SEXPORTS 0

    #if __GNUC__ >= 4
        #define SKIP_DLL __attribute__((visibility("hidden")))
        #define EXPORT_DLL __attribute__((visibility("default")))
    #else
        #define SKIP_DLL
        #define EXPORT_DLL
    #endif
#endif


// define any constant if present

#endif
// ************************************************************************* //