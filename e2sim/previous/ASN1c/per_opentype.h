/*****************************************************************************
#                                                                            *
# Copyright 2019 AT&T Intellectual Property                                  *
#                                                                            *
# Licensed under the Apache License, Version 2.0 (the "License");            *
# you may not use this file except in compliance with the License.           *
# You may obtain a copy of the License at                                    *
#                                                                            *
#      http://www.apache.org/licenses/LICENSE-2.0                            *
#                                                                            *
# Unless required by applicable law or agreed to in writing, software        *
# distributed under the License is distributed on an "AS IS" BASIS,          *
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   *
# See the License for the specific language governing permissions and        *
# limitations under the License.                                             *
#                                                                            *
******************************************************************************/

/*
 * Copyright (c) 2007-2017 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_PER_OPENTYPE_H_
#define	_PER_OPENTYPE_H_

#ifdef __cplusplus
extern "C" {
#endif

asn_dec_rval_t uper_open_type_get(const asn_codec_ctx_t *opt_codec_ctx,
                                  const asn_TYPE_descriptor_t *td,
                                  const asn_per_constraints_t *constraints,
                                  void **sptr, asn_per_data_t *pd);

int uper_open_type_skip(const asn_codec_ctx_t *opt_codec_ctx,
                        asn_per_data_t *pd);

/*
 * X.691 (2015/08), #11.2
 * Returns -1 if error is encountered. 0 if all OK.
 */
int uper_open_type_put(const asn_TYPE_descriptor_t *td,
                       const asn_per_constraints_t *constraints,
                       const void *sptr, asn_per_outp_t *po);

asn_dec_rval_t aper_open_type_get(const asn_codec_ctx_t *opt_codec_ctx,
                                  const asn_TYPE_descriptor_t *td,
                                  const asn_per_constraints_t *constraints,
                                  void **sptr, asn_per_data_t *pd);


int aper_open_type_skip(const asn_codec_ctx_t *opt_codec_ctx, asn_per_data_t *pd);

int aper_open_type_put(const asn_TYPE_descriptor_t *td,
                       const asn_per_constraints_t *constraints,
                       const void *sptr, asn_per_outp_t *po);

#ifdef __cplusplus
}
#endif

#endif	/* _PER_OPENTYPE_H_ */
