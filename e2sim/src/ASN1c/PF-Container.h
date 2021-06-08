/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-KPM-RC"
 * 	found in "e2sm-kpm-rc.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -fno-include-deps -findirect-choice -gen-PER -D .`
 */

#ifndef	_PF_Container_H_
#define	_PF_Container_H_


#include "asn_application.h"

/* Including external dependencies */
#include "constr_CHOICE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum PF_Container_PR {
	PF_Container_PR_NOTHING,	/* No components present */
	PF_Container_PR_oDU,
	PF_Container_PR_oCU_CP,
	PF_Container_PR_oCU_UP
} PF_Container_PR;

/* Forward declarations */
struct ODU_PF_Container;
struct OCUCP_PF_Container;
struct OCUUP_PF_Container;

/* PF-Container */
typedef struct PF_Container {
	PF_Container_PR present;
	union PF_Container_u {
		struct ODU_PF_Container	*oDU;
		struct OCUCP_PF_Container	*oCU_CP;
		struct OCUUP_PF_Container	*oCU_UP;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PF_Container_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PF_Container;
extern asn_CHOICE_specifics_t asn_SPC_PF_Container_specs_1;
extern asn_TYPE_member_t asn_MBR_PF_Container_1[3];
extern asn_per_constraints_t asn_PER_type_PF_Container_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _PF_Container_H_ */
#include "asn_internal.h"
