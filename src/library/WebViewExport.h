#pragma once
#if defined(BuildCoreWebViewStaticLib)
#	define WebViewExport 
#elif defined(BuildCoreWebViewDLL)
#	define WebViewExport __declspec(dllexport)
#else
#	define WebViewExport __declspec(dllimport)
#endif