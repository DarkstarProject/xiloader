

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Tue Jan 28 21:15:45 2014
 */
/* Compiler settings for ffxi.idl:
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


#ifndef __FFXi_h__
#define __FFXi_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___IFFXiEntryEvents_FWD_DEFINED__
#define ___IFFXiEntryEvents_FWD_DEFINED__
typedef interface _IFFXiEntryEvents _IFFXiEntryEvents;

#endif 	/* ___IFFXiEntryEvents_FWD_DEFINED__ */


#ifndef __IFxFileManager_FWD_DEFINED__
#define __IFxFileManager_FWD_DEFINED__
typedef interface IFxFileManager IFxFileManager;

#endif 	/* __IFxFileManager_FWD_DEFINED__ */


#ifndef __IFFXiEntry_FWD_DEFINED__
#define __IFFXiEntry_FWD_DEFINED__
typedef interface IFFXiEntry IFFXiEntry;

#endif 	/* __IFFXiEntry_FWD_DEFINED__ */


#ifndef __FFXiEntry_FWD_DEFINED__
#define __FFXiEntry_FWD_DEFINED__

#ifdef __cplusplus
typedef class FFXiEntry FFXiEntry;
#else
typedef struct FFXiEntry FFXiEntry;
#endif /* __cplusplus */

#endif 	/* __FFXiEntry_FWD_DEFINED__ */


#ifndef __FxFileManager_FWD_DEFINED__
#define __FxFileManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class FxFileManager FxFileManager;
#else
typedef struct FxFileManager FxFileManager;
#endif /* __cplusplus */

#endif 	/* __FxFileManager_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __FFXILib_LIBRARY_DEFINED__
#define __FFXILib_LIBRARY_DEFINED__

/* library FFXILib */
/* [custom][custom][helpstring][version][uuid] */ 




typedef struct tag_FX_FILE_DATA
    {
    unsigned short FileNo;
    unsigned char *pBufAddr;
    } 	_FX_FILE_DATA;


EXTERN_C const IID LIBID_FFXILib;

#ifndef ___IFFXiEntryEvents_DISPINTERFACE_DEFINED__
#define ___IFFXiEntryEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IFFXiEntryEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IFFXiEntryEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("989D790E-6236-11D4-80E9-00105A81E890")
    _IFFXiEntryEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IFFXiEntryEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IFFXiEntryEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IFFXiEntryEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IFFXiEntryEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IFFXiEntryEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IFFXiEntryEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IFFXiEntryEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IFFXiEntryEvents * This,
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
        
        END_INTERFACE
    } _IFFXiEntryEventsVtbl;

    interface _IFFXiEntryEvents
    {
        CONST_VTBL struct _IFFXiEntryEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IFFXiEntryEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IFFXiEntryEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IFFXiEntryEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IFFXiEntryEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IFFXiEntryEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IFFXiEntryEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IFFXiEntryEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IFFXiEntryEvents_DISPINTERFACE_DEFINED__ */


#ifndef __IFxFileManager_INTERFACE_DEFINED__
#define __IFxFileManager_INTERFACE_DEFINED__

/* interface IFxFileManager */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IFxFileManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("56C0E4F1-2E0C-4777-879F-7D2FD3ADCEAF")
    IFxFileManager : public IUnknown
    {
    public:
        virtual HRESULT __stdcall FxFileSystemInit( 
            /* [in] */ unsigned char *pNameFile) = 0;
        
        virtual HRESULT __stdcall FxFileSystemExit( void) = 0;
        
        virtual HRESULT __stdcall FxRead( 
            /* [in] */ unsigned short FileNo,
            /* [in] */ unsigned char *pBufAddr) = 0;
        
        virtual HRESULT __stdcall FxReadA( 
            /* [in] */ unsigned short FileNo,
            /* [in] */ unsigned char *pBufAddr) = 0;
        
        virtual HRESULT __stdcall FxReadM( 
            /* [in] */ _FX_FILE_DATA *FileData,
            /* [in] */ unsigned int FileDataNum) = 0;
        
        virtual HRESULT __stdcall FxReadEx( 
            /* [in] */ unsigned short FileNo,
            /* [in] */ unsigned long StartOffset,
            /* [in] */ void *CtrlFunc) = 0;
        
        virtual HRESULT __stdcall FxWrite( 
            /* [in] */ unsigned short FileNo,
            /* [in] */ unsigned long WriteLength,
            /* [in] */ unsigned char *pBufAddr) = 0;
        
        virtual HRESULT __stdcall FxSeek( 
            /* [in] */ unsigned short FileNo) = 0;
        
        virtual HRESULT __stdcall FxGetFileSize( 
            /* [in] */ unsigned short FileNo,
            /* [out] */ unsigned long *FileLength) = 0;
        
        virtual HRESULT __stdcall FxTestFileSize( 
            /* [in] */ unsigned short FileNo,
            /* [out] */ unsigned long *FileLength) = 0;
        
        virtual HRESULT __stdcall FxFinishedCheck( 
            /* [in] */ unsigned short FileNo,
            /* [out] */ unsigned char *bFinishedFlg) = 0;
        
        virtual HRESULT __stdcall FxFinishedCheckB( 
            /* [in] */ unsigned char *pBufAddr,
            /* [out] */ unsigned char *bFinishedFlg) = 0;
        
        virtual HRESULT __stdcall FxWait( void) = 0;
        
        virtual HRESULT __stdcall FxPeriodicCheck( void) = 0;
        
        virtual HRESULT __stdcall FxGetFileSysteStatus( 
            /* [out] */ long *Status) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFxFileManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFxFileManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFxFileManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFxFileManager * This);
        
        HRESULT ( __stdcall *FxFileSystemInit )( 
            IFxFileManager * This,
            /* [in] */ unsigned char *pNameFile);
        
        HRESULT ( __stdcall *FxFileSystemExit )( 
            IFxFileManager * This);
        
        HRESULT ( __stdcall *FxRead )( 
            IFxFileManager * This,
            /* [in] */ unsigned short FileNo,
            /* [in] */ unsigned char *pBufAddr);
        
        HRESULT ( __stdcall *FxReadA )( 
            IFxFileManager * This,
            /* [in] */ unsigned short FileNo,
            /* [in] */ unsigned char *pBufAddr);
        
        HRESULT ( __stdcall *FxReadM )( 
            IFxFileManager * This,
            /* [in] */ _FX_FILE_DATA *FileData,
            /* [in] */ unsigned int FileDataNum);
        
        HRESULT ( __stdcall *FxReadEx )( 
            IFxFileManager * This,
            /* [in] */ unsigned short FileNo,
            /* [in] */ unsigned long StartOffset,
            /* [in] */ void *CtrlFunc);
        
        HRESULT ( __stdcall *FxWrite )( 
            IFxFileManager * This,
            /* [in] */ unsigned short FileNo,
            /* [in] */ unsigned long WriteLength,
            /* [in] */ unsigned char *pBufAddr);
        
        HRESULT ( __stdcall *FxSeek )( 
            IFxFileManager * This,
            /* [in] */ unsigned short FileNo);
        
        HRESULT ( __stdcall *FxGetFileSize )( 
            IFxFileManager * This,
            /* [in] */ unsigned short FileNo,
            /* [out] */ unsigned long *FileLength);
        
        HRESULT ( __stdcall *FxTestFileSize )( 
            IFxFileManager * This,
            /* [in] */ unsigned short FileNo,
            /* [out] */ unsigned long *FileLength);
        
        HRESULT ( __stdcall *FxFinishedCheck )( 
            IFxFileManager * This,
            /* [in] */ unsigned short FileNo,
            /* [out] */ unsigned char *bFinishedFlg);
        
        HRESULT ( __stdcall *FxFinishedCheckB )( 
            IFxFileManager * This,
            /* [in] */ unsigned char *pBufAddr,
            /* [out] */ unsigned char *bFinishedFlg);
        
        HRESULT ( __stdcall *FxWait )( 
            IFxFileManager * This);
        
        HRESULT ( __stdcall *FxPeriodicCheck )( 
            IFxFileManager * This);
        
        HRESULT ( __stdcall *FxGetFileSysteStatus )( 
            IFxFileManager * This,
            /* [out] */ long *Status);
        
        END_INTERFACE
    } IFxFileManagerVtbl;

    interface IFxFileManager
    {
        CONST_VTBL struct IFxFileManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFxFileManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFxFileManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFxFileManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFxFileManager_FxFileSystemInit(This,pNameFile)	\
    ( (This)->lpVtbl -> FxFileSystemInit(This,pNameFile) ) 

#define IFxFileManager_FxFileSystemExit(This)	\
    ( (This)->lpVtbl -> FxFileSystemExit(This) ) 

#define IFxFileManager_FxRead(This,FileNo,pBufAddr)	\
    ( (This)->lpVtbl -> FxRead(This,FileNo,pBufAddr) ) 

#define IFxFileManager_FxReadA(This,FileNo,pBufAddr)	\
    ( (This)->lpVtbl -> FxReadA(This,FileNo,pBufAddr) ) 

#define IFxFileManager_FxReadM(This,FileData,FileDataNum)	\
    ( (This)->lpVtbl -> FxReadM(This,FileData,FileDataNum) ) 

#define IFxFileManager_FxReadEx(This,FileNo,StartOffset,CtrlFunc)	\
    ( (This)->lpVtbl -> FxReadEx(This,FileNo,StartOffset,CtrlFunc) ) 

#define IFxFileManager_FxWrite(This,FileNo,WriteLength,pBufAddr)	\
    ( (This)->lpVtbl -> FxWrite(This,FileNo,WriteLength,pBufAddr) ) 

#define IFxFileManager_FxSeek(This,FileNo)	\
    ( (This)->lpVtbl -> FxSeek(This,FileNo) ) 

#define IFxFileManager_FxGetFileSize(This,FileNo,FileLength)	\
    ( (This)->lpVtbl -> FxGetFileSize(This,FileNo,FileLength) ) 

#define IFxFileManager_FxTestFileSize(This,FileNo,FileLength)	\
    ( (This)->lpVtbl -> FxTestFileSize(This,FileNo,FileLength) ) 

#define IFxFileManager_FxFinishedCheck(This,FileNo,bFinishedFlg)	\
    ( (This)->lpVtbl -> FxFinishedCheck(This,FileNo,bFinishedFlg) ) 

#define IFxFileManager_FxFinishedCheckB(This,pBufAddr,bFinishedFlg)	\
    ( (This)->lpVtbl -> FxFinishedCheckB(This,pBufAddr,bFinishedFlg) ) 

#define IFxFileManager_FxWait(This)	\
    ( (This)->lpVtbl -> FxWait(This) ) 

#define IFxFileManager_FxPeriodicCheck(This)	\
    ( (This)->lpVtbl -> FxPeriodicCheck(This) ) 

#define IFxFileManager_FxGetFileSysteStatus(This,Status)	\
    ( (This)->lpVtbl -> FxGetFileSysteStatus(This,Status) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFxFileManager_INTERFACE_DEFINED__ */


#ifndef __IFFXiEntry_INTERFACE_DEFINED__
#define __IFFXiEntry_INTERFACE_DEFINED__

/* interface IFFXiEntry */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IFFXiEntry;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("989D790C-6236-11D4-80E9-00105A81E890")
    IFFXiEntry : public IUnknown
    {
    public:
        virtual HRESULT __stdcall GameStart( 
            /* [in] */ IUnknown *pPol,
            /* [out] */ IUnknown **pFFXiMessage) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT __stdcall get_FxFileManager( 
            /* [retval][out] */ IFxFileManager **pVal) = 0;
        
        virtual HRESULT __stdcall getVersion( 
            /* [retval][out] */ unsigned long *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFFXiEntryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFFXiEntry * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFFXiEntry * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFFXiEntry * This);
        
        HRESULT ( __stdcall *GameStart )( 
            IFFXiEntry * This,
            /* [in] */ IUnknown *pPol,
            /* [out] */ IUnknown **pFFXiMessage);
        
        /* [helpstring][propget] */ HRESULT ( __stdcall *get_FxFileManager )( 
            IFFXiEntry * This,
            /* [retval][out] */ IFxFileManager **pVal);
        
        HRESULT ( __stdcall *getVersion )( 
            IFFXiEntry * This,
            /* [retval][out] */ unsigned long *pVal);
        
        END_INTERFACE
    } IFFXiEntryVtbl;

    interface IFFXiEntry
    {
        CONST_VTBL struct IFFXiEntryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFFXiEntry_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFFXiEntry_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFFXiEntry_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFFXiEntry_GameStart(This,pPol,pFFXiMessage)	\
    ( (This)->lpVtbl -> GameStart(This,pPol,pFFXiMessage) ) 

#define IFFXiEntry_get_FxFileManager(This,pVal)	\
    ( (This)->lpVtbl -> get_FxFileManager(This,pVal) ) 

#define IFFXiEntry_getVersion(This,pVal)	\
    ( (This)->lpVtbl -> getVersion(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFFXiEntry_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_FFXiEntry;

#ifdef __cplusplus

class DECLSPEC_UUID("989D790D-6236-11D4-80E9-00105A81E890")
FFXiEntry;
#endif

EXTERN_C const CLSID CLSID_FxFileManager;

#ifdef __cplusplus

class DECLSPEC_UUID("0DF0E951-D03C-4A94-90EF-40AE60668F5F")
FxFileManager;
#endif
#endif /* __FFXILib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


