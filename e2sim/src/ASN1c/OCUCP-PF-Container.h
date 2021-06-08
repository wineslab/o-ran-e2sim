/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-KPM-RC"
 * 	found in "e2sm-kpm-rc.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -fno-include-deps -findirect-choice -gen-PER -D .`
 */

#ifndef	_OCUCP_PF_Container_H_
#define	_OCUCP_PF_Container_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* OCUCP-PF-Container */
typedef struct OCUCP_PF_Container {
	struct OCUCP_PF_Container__cu_CP_Resource_Status {
		long	*numberOfActive_UEs	/* OPTIONAL */;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} cu_CP_Resource_Status;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} OCUCP_PF_Container_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_OCUCP_PF_Container;
extern asn_SEQUENCE_specifics_t asn_SPC_OCUCP_PF_Container_specs_1;
extern asn_TYPE_member_t asn_MBR_OCUCP_PF_Container_1[1];

#ifdef __cplusplus
}
#endif

#endif	/* _OCUCP_PF_Container_H_ */
#include "asn_internal.h"
