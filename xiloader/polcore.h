

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Tue Jan 28 21:36:22 2014
 */
/* Compiler settings for polcore.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __polcore_h__
#define __polcore_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IPOLCoreCom_FWD_DEFINED__
#define __IPOLCoreCom_FWD_DEFINED__
typedef interface IPOLCoreCom IPOLCoreCom;

#endif 	/* __IPOLCoreCom_FWD_DEFINED__ */


#ifndef ___IPOLCoreComEvents_FWD_DEFINED__
#define ___IPOLCoreComEvents_FWD_DEFINED__
typedef interface _IPOLCoreComEvents _IPOLCoreComEvents;

#endif 	/* ___IPOLCoreComEvents_FWD_DEFINED__ */


#ifndef __POLCoreCom_FWD_DEFINED__
#define __POLCoreCom_FWD_DEFINED__

#ifdef __cplusplus
typedef class POLCoreCom POLCoreCom;
#else
typedef struct POLCoreCom POLCoreCom;
#endif /* __cplusplus */

#endif 	/* __POLCoreCom_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __POLCORELib_LIBRARY_DEFINED__
#define __POLCORELib_LIBRARY_DEFINED__

/* library POLCORELib */
/* [custom][custom][custom][helpstring][version][uuid] */ 

EXTERN_C const IID LIBID_POLCORELib;

#ifndef __IPOLCoreCom_INTERFACE_DEFINED__
#define __IPOLCoreCom_INTERFACE_DEFINED__

/* interface IPOLCoreCom */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IPOLCoreCom;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E0516654-EF77-435D-AA7D-50D2C069CE34")
    IPOLCoreCom : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT __stdcall GethInstance( 
            /* [out] */ HINSTANCE__ **hInstance) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall GetlpCmdLine( 
            /* [out] */ LPSTR *lpCmdLine) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall SetParamInit( 
            /* [in] */ HINSTANCE__ *hInstance,
            /* [in] */ LPSTR lpCmdLine) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall GetWindowsType( 
            /* [out] */ unsigned long *winType) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall GetCommonFunctionTable( 
            /* [out] */ unsigned long **ptr) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall PolViewerExec( 
            /* [in] */ unsigned long *inFunc) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall GetWindowsVersion( 
            /* [out] */ unsigned long *outPlatformId,
            /* [out] */ unsigned long *outMajor,
            /* [out] */ unsigned long *outMinor,
            /* [out] */ unsigned long *outSPMajor,
            /* [out] */ BSTR *outOSName,
            /* [in] */ unsigned long inOSNameSize) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall PressAnyKey( 
            /* [in] */ unsigned long inType) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall PolconSetEnableWakeupFuncFlag( 
            /* [in] */ unsigned long inType,
            /* [in] */ unsigned long inBool) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall CreateInput( 
            /* [in] */ wireHWND inWnd) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall UpdateInputState( void) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall GetPadRepeat( 
            /* [in] */ unsigned long inPanNum,
            /* [out] */ unsigned long *outState) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall GetPadOn( 
            /* [in] */ unsigned long inPanNum,
            /* [out] */ unsigned long *outState) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall FinalCleanup( void) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall SetParamInitW( 
            /* [in] */ HINSTANCE__ *hInstance,
            /* [in] */ LPWSTR lpCmdLine) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall GetlpCmdLineW( 
            /* [out] */ LPWSTR *lpCmdLine) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall PaintFriendList( 
            /* [in] */ wireHDC hdc) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall CreateFriendList( void) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall DestroyFriendList( void) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall SetMaskWindowHandle( 
            wireHWND hWnd) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall GetPlayOnlineRegKeyNameW( 
            /* [out] */ LPWSTR *outName) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall GetPlayOnlineRegKeyNameA( 
            /* [out] */ LPSTR *outName) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall GetSquareEnixRegKeyNameW( 
            /* [out] */ LPWSTR *outName) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall GetSquareEnixRegKeyNameA( 
            /* [out] */ LPSTR *outName) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall SetAreaCode( 
            /* [in] */ long inAreaCode) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall GetAreaCode( 
            /* [out] */ long *outAreaCode) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall HideMaskWindow( 
            /* [in] */ long inCode) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall ShowMaskWindow( 
            /* [in] */ long inCode) = 0;
        
        virtual /* [helpstring] */ HRESULT __stdcall IsVisibleMaskWindow( 
            /* [out] */ long *outIsVisible) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPOLCoreComVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPOLCoreCom * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPOLCoreCom * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPOLCoreCom * This);
        
        /* [helpstring] */ HRESULT ( __stdcall *GethInstance )( 
            IPOLCoreCom * This,
            /* [out] */ HINSTANCE__ **hInstance);
        
        /* [helpstring] */ HRESULT ( __stdcall *GetlpCmdLine )( 
            IPOLCoreCom * This,
            /* [out] */ LPSTR *lpCmdLine);
        
        /* [helpstring] */ HRESULT ( __stdcall *SetParamInit )( 
            IPOLCoreCom * This,
            /* [in] */ HINSTANCE__ *hInstance,
            /* [in] */ LPSTR lpCmdLine);
        
        /* [helpstring] */ HRESULT ( __stdcall *GetWindowsType )( 
            IPOLCoreCom * This,
            /* [out] */ unsigned long *winType);
        
        /* [helpstring] */ HRESULT ( __stdcall *GetCommonFunctionTable )( 
            IPOLCoreCom * This,
            /* [out] */ unsigned long **ptr);
        
        /* [helpstring] */ HRESULT ( __stdcall *PolViewerExec )( 
            IPOLCoreCom * This,
            /* [in] */ unsigned long *inFunc);
        
        /* [helpstring] */ HRESULT ( __stdcall *GetWindowsVersion )( 
            IPOLCoreCom * This,
            /* [out] */ unsigned long *outPlatformId,
            /* [out] */ unsigned long *outMajor,
            /* [out] */ unsigned long *outMinor,
            /* [out] */ unsigned long *outSPMajor,
            /* [out] */ BSTR *outOSName,
            /* [in] */ unsigned long inOSNameSize);
        
        /* [helpstring] */ HRESULT ( __stdcall *PressAnyKey )( 
            IPOLCoreCom * This,
            /* [in] */ unsigned long inType);
        
        /* [helpstring] */ HRESULT ( __stdcall *PolconSetEnableWakeupFuncFlag )( 
            IPOLCoreCom * This,
            /* [in] */ unsigned long inType,
            /* [in] */ unsigned long inBool);
        
        /* [helpstring] */ HRESULT ( __stdcall *CreateInput )( 
            IPOLCoreCom * This,
            /* [in] */ wireHWND inWnd);
        
        /* [helpstring] */ HRESULT ( __stdcall *UpdateInputState )( 
            IPOLCoreCom * This);
        
        /* [helpstring] */ HRESULT ( __stdcall *GetPadRepeat )( 
            IPOLCoreCom * This,
            /* [in] */ unsigned long inPanNum,
            /* [out] */ unsigned long *outState);
        
        /* [helpstring] */ HRESULT ( __stdcall *GetPadOn )( 
            IPOLCoreCom * This,
            /* [in] */ unsigned long inPanNum,
            /* [out] */ unsigned long *outState);
        
        /* [helpstring] */ HRESULT ( __stdcall *FinalCleanup )( 
            IPOLCoreCom * This);
        
        /* [helpstring] */ HRESULT ( __stdcall *SetParamInitW )( 
            IPOLCoreCom * This,
            /* [in] */ HINSTANCE__ *hInstance,
            /* [in] */ LPWSTR lpCmdLine);
        
        /* [helpstring] */ HRESULT ( __stdcall *GetlpCmdLineW )( 
            IPOLCoreCom * This,
            /* [out] */ LPWSTR *lpCmdLine);
        
        /* [helpstring] */ HRESULT ( __stdcall *PaintFriendList )( 
            IPOLCoreCom * This,
            /* [in] */ wireHDC hdc);
        
        /* [helpstring] */ HRESULT ( __stdcall *CreateFriendList )( 
            IPOLCoreCom * This);
        
        /* [helpstring] */ HRESULT ( __stdcall *DestroyFriendList )( 
            IPOLCoreCom * This);
        
        /* [helpstring] */ HRESULT ( __stdcall *SetMaskWindowHandle )( 
            IPOLCoreCom * This,
            wireHWND hWnd);
        
        /* [helpstring] */ HRESULT ( __stdcall *GetPlayOnlineRegKeyNameW )( 
            IPOLCoreCom * This,
            /* [out] */ LPWSTR *outName);
        
        /* [helpstring] */ HRESULT ( __stdcall *GetPlayOnlineRegKeyNameA )( 
            IPOLCoreCom * This,
            /* [out] */ LPSTR *outName);
        
        /* [helpstring] */ HRESULT ( __stdcall *GetSquareEnixRegKeyNameW )( 
            IPOLCoreCom * This,
            /* [out] */ LPWSTR *outName);
        
        /* [helpstring] */ HRESULT ( __stdcall *GetSquareEnixRegKeyNameA )( 
            IPOLCoreCom * This,
            /* [out] */ LPSTR *outName);
        
        /* [helpstring] */ HRESULT ( __stdcall *SetAreaCode )( 
            IPOLCoreCom * This,
            /* [in] */ long inAreaCode);
        
        /* [helpstring] */ HRESULT ( __stdcall *GetAreaCode )( 
            IPOLCoreCom * This,
            /* [out] */ long *outAreaCode);
        
        /* [helpstring] */ HRESULT ( __stdcall *HideMaskWindow )( 
            IPOLCoreCom * This,
            /* [in] */ long inCode);
        
        /* [helpstring] */ HRESULT ( __stdcall *ShowMaskWindow )( 
            IPOLCoreCom * This,
            /* [in] */ long inCode);
        
        /* [helpstring] */ HRESULT ( __stdcall *IsVisibleMaskWindow )( 
            IPOLCoreCom * This,
            /* [out] */ long *outIsVisible);
        
        END_INTERFACE
    } IPOLCoreComVtbl;

    interface IPOLCoreCom
    {
        CONST_VTBL struct IPOLCoreComVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPOLCoreCom_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPOLCoreCom_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPOLCoreCom_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPOLCoreCom_GethInstance(This,hInstance)	\
    ( (This)->lpVtbl -> GethInstance(This,hInstance) ) 

#define IPOLCoreCom_GetlpCmdLine(This,lpCmdLine)	\
    ( (This)->lpVtbl -> GetlpCmdLine(This,lpCmdLine) ) 

#define IPOLCoreCom_SetParamInit(This,hInstance,lpCmdLine)	\
    ( (This)->lpVtbl -> SetParamInit(This,hInstance,lpCmdLine) ) 

#define IPOLCoreCom_GetWindowsType(This,winType)	\
    ( (This)->lpVtbl -> GetWindowsType(This,winType) ) 

#define IPOLCoreCom_GetCommonFunctionTable(This,ptr)	\
    ( (This)->lpVtbl -> GetCommonFunctionTable(This,ptr) ) 

#define IPOLCoreCom_PolViewerExec(This,inFunc)	\
    ( (This)->lpVtbl -> PolViewerExec(This,inFunc) ) 

#define IPOLCoreCom_GetWindowsVersion(This,outPlatformId,outMajor,outMinor,outSPMajor,outOSName,inOSNameSize)	\
    ( (This)->lpVtbl -> GetWindowsVersion(This,outPlatformId,outMajor,outMinor,outSPMajor,outOSName,inOSNameSize) ) 

#define IPOLCoreCom_PressAnyKey(This,inType)	\
    ( (This)->lpVtbl -> PressAnyKey(This,inType) ) 

#define IPOLCoreCom_PolconSetEnableWakeupFuncFlag(This,inType,inBool)	\
    ( (This)->lpVtbl -> PolconSetEnableWakeupFuncFlag(This,inType,inBool) ) 

#define IPOLCoreCom_CreateInput(This,inWnd)	\
    ( (This)->lpVtbl -> CreateInput(This,inWnd) ) 

#define IPOLCoreCom_UpdateInputState(This)	\
    ( (This)->lpVtbl -> UpdateInputState(This) ) 

#define IPOLCoreCom_GetPadRepeat(This,inPanNum,outState)	\
    ( (This)->lpVtbl -> GetPadRepeat(This,inPanNum,outState) ) 

#define IPOLCoreCom_GetPadOn(This,inPanNum,outState)	\
    ( (This)->lpVtbl -> GetPadOn(This,inPanNum,outState) ) 

#define IPOLCoreCom_FinalCleanup(This)	\
    ( (This)->lpVtbl -> FinalCleanup(This) ) 

#define IPOLCoreCom_SetParamInitW(This,hInstance,lpCmdLine)	\
    ( (This)->lpVtbl -> SetParamInitW(This,hInstance,lpCmdLine) ) 

#define IPOLCoreCom_GetlpCmdLineW(This,lpCmdLine)	\
    ( (This)->lpVtbl -> GetlpCmdLineW(This,lpCmdLine) ) 

#define IPOLCoreCom_PaintFriendList(This,hdc)	\
    ( (This)->lpVtbl -> PaintFriendList(This,hdc) ) 

#define IPOLCoreCom_CreateFriendList(This)	\
    ( (This)->lpVtbl -> CreateFriendList(This) ) 

#define IPOLCoreCom_DestroyFriendList(This)	\
    ( (This)->lpVtbl -> DestroyFriendList(This) ) 

#define IPOLCoreCom_SetMaskWindowHandle(This,hWnd)	\
    ( (This)->lpVtbl -> SetMaskWindowHandle(This,hWnd) ) 

#define IPOLCoreCom_GetPlayOnlineRegKeyNameW(This,outName)	\
    ( (This)->lpVtbl -> GetPlayOnlineRegKeyNameW(This,outName) ) 

#define IPOLCoreCom_GetPlayOnlineRegKeyNameA(This,outName)	\
    ( (This)->lpVtbl -> GetPlayOnlineRegKeyNameA(This,outName) ) 

#define IPOLCoreCom_GetSquareEnixRegKeyNameW(This,outName)	\
    ( (This)->lpVtbl -> GetSquareEnixRegKeyNameW(This,outName) ) 

#define IPOLCoreCom_GetSquareEnixRegKeyNameA(This,outName)	\
    ( (This)->lpVtbl -> GetSquareEnixRegKeyNameA(This,outName) ) 

#define IPOLCoreCom_SetAreaCode(This,inAreaCode)	\
    ( (This)->lpVtbl -> SetAreaCode(This,inAreaCode) ) 

#define IPOLCoreCom_GetAreaCode(This,outAreaCode)	\
    ( (This)->lpVtbl -> GetAreaCode(This,outAreaCode) ) 

#define IPOLCoreCom_HideMaskWindow(This,inCode)	\
    ( (This)->lpVtbl -> HideMaskWindow(This,inCode) ) 

#define IPOLCoreCom_ShowMaskWindow(This,inCode)	\
    ( (This)->lpVtbl -> ShowMaskWindow(This,inCode) ) 

#define IPOLCoreCom_IsVisibleMaskWindow(This,outIsVisible)	\
    ( (This)->lpVtbl -> IsVisibleMaskWindow(This,outIsVisible) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPOLCoreCom_INTERFACE_DEFINED__ */


#ifndef ___IPOLCoreComEvents_INTERFACE_DEFINED__
#define ___IPOLCoreComEvents_INTERFACE_DEFINED__

/* interface _IPOLCoreComEvents */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID__IPOLCoreComEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0B197CB5-DAFD-48B8-97D2-71E0A776AE4C")
    _IPOLCoreComEvents : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PolViewerExec( 
            /* [in] */ unsigned long *inFunc) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MaskWindow( 
            /* [out][in] */ long *ioCode,
            /* [in] */ long inType) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct _IPOLCoreComEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IPOLCoreComEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IPOLCoreComEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IPOLCoreComEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IPOLCoreComEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IPOLCoreComEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IPOLCoreComEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IPOLCoreComEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PolViewerExec )( 
            _IPOLCoreComEvents * This,
            /* [in] */ unsigned long *inFunc);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MaskWindow )( 
            _IPOLCoreComEvents * This,
            /* [out][in] */ long *ioCode,
            /* [in] */ long inType);
        
        END_INTERFACE
    } _IPOLCoreComEventsVtbl;

    interface _IPOLCoreComEvents
    {
        CONST_VTBL struct _IPOLCoreComEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IPOLCoreComEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IPOLCoreComEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IPOLCoreComEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IPOLCoreComEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IPOLCoreComEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IPOLCoreComEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IPOLCoreComEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define _IPOLCoreComEvents_PolViewerExec(This,inFunc)	\
    ( (This)->lpVtbl -> PolViewerExec(This,inFunc) ) 

#define _IPOLCoreComEvents_MaskWindow(This,ioCode,inType)	\
    ( (This)->lpVtbl -> MaskWindow(This,ioCode,inType) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ___IPOLCoreComEvents_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_POLCoreCom;

#ifdef __cplusplus

class DECLSPEC_UUID("3501F5DD-7894-42DF-866A-A2B6527D8049")
POLCoreCom;
#endif
#endif /* __POLCORELib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


