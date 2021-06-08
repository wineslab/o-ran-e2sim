/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-KPM-RC"
 * 	found in "e2sm-kpm-rc.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -fno-include-deps -findirect-choice -gen-PER -D .`
 */

#include "ServedPlmnPerCellListItem.h"

#include "FGC-DU-PM-Container.h"
#include "EPC-DU-PM-Container.h"
asn_TYPE_member_t asn_MBR_ServedPlmnPerCellListItem_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct ServedPlmnPerCellListItem, pLMN_Identity),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PLMN_Identity,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"pLMN-Identity"
		},
	{ ATF_POINTER, 2, offsetof(struct ServedPlmnPerCellListItem, du_PM_5GC),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_FGC_DU_PM_Container,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"du-PM-5GC"
		},
	{ ATF_POINTER, 1, offsetof(struct ServedPlmnPerCellListItem, du_PM_EPC),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_EPC_DU_PM_Container,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"du-PM-EPC"
		},
};
static const int asn_MAP_ServedPlmnPerCellListItem_oms_1[] = { 1, 2 };
static const ber_tlv_tag_t asn_DEF_ServedPlmnPerCellListItem_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_ServedPlmnPerCellListItem_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* pLMN-Identity */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* du-PM-5GC */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* du-PM-EPC */
};
asn_SEQUENCE_specifics_t asn_SPC_ServedPlmnPerCellListItem_specs_1 = {
	sizeof(struct ServedPlmnPerCellListItem),
	offsetof(struct ServedPlmnPerCellListItem, _asn_ctx),
	asn_MAP_ServedPlmnPerCellListItem_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_ServedPlmnPerCellListItem_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	3,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_ServedPlmnPerCellListItem = {
	"ServedPlmnPerCellListItem",
	"ServedPlmnPerCellListItem",
	&asn_OP_SEQUENCE,
	asn_DEF_ServedPlmnPerCellListItem_tags_1,
	sizeof(asn_DEF_ServedPlmnPerCellListItem_tags_1)
		/sizeof(asn_DEF_ServedPlmnPerCellListItem_tags_1[0]), /* 1 */
	asn_DEF_ServedPlmnPerCellListItem_tags_1,	/* Same as above */
	sizeof(asn_DEF_ServedPlmnPerCellListItem_tags_1)
		/sizeof(asn_DEF_ServedPlmnPerCellListItem_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_ServedPlmnPerCellListItem_1,
	3,	/* Elements count */
	&asn_SPC_ServedPlmnPerCellListItem_specs_1	/* Additional specs */
};

