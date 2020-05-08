#!/bin/bash
################################################################################
#   Copyright (c) 2019 AT&T Intellectual Property.                             #
#   Copyright (c) 2019 Nokia.                                                  #
#                                                                              #
#   Licensed under the Apache License, Version 2.0 (the "License");            #
#   you may not use this file except in compliance with the License.           #
#   You may obtain a copy of the License at                                    #
#                                                                              #
#       http://www.apache.org/licenses/LICENSE-2.0                             #
#                                                                              #
#   Unless required by applicable law or agreed to in writing, software        #
#   distributed under the License is distributed on an "AS IS" BASIS,          #
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   #
#   See the License for the specific language governing permissions and        #
#   limitations under the License.                                             #
################################################################################


OVERRIDEYAML=$1


DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"

#/root/test/ric_robot_suite/helm
# extract the base to find root to dep

BASE=${DIR%/test*}

# /data/ORAN-OSC/it/dep/ric-platform/50-RIC-Platform/bin/install
BASEDIR05=$BASE/dep/ric-platform/50-RIC-Platform/
BASEDIRCOMMON=$BASE/dep/ric-common/Common-Template/helm/ric-common

echo "Using etc/ric.conf from $BASEDIR05"


source $BASEDIR05/etc/ric.conf


if [ -z "$RICPLT_RELEASE_NAME" ];then
   RELEASE_NAME=$helm_release_name
else
   RELEASE_NAME=$RICPLT_RELEASE_NAME
fi

# Namespace configuration
if [ -z "$RICPLT_NAMESPACE" ];then
   PLT_NAMESPACE=$plt_namespace
else
   PLT_NAMESPACE=$RICPLT_NAMESPACE
fi



RICPLT_COMPONENTS="e2sim"

echo "Deploying RIC Platform components [$RICPLT_COMPONENTS]"
echo "Platform Namespace: $PLT_NAMESPACE"
echo "Helm Release Name: $RELEASE_NAME"


COMMON_CHART_VERSION=$(cat $BASEDIRCOMMON/Chart.yaml | grep version | awk '{print $2}')

helm package -d /tmp $BASEDIRCOMMON


for component in $RICPLT_COMPONENTS; do
  echo "Preparing chart for comonent $component"
  mkdir -p $DIR/$component/charts/
  cp /tmp/ric-common-$COMMON_CHART_VERSION.tgz $DIR/$component/charts/
  if [ -z $OVERRIDEYAML ]; then
  echo "helm install --namespace \"${PLT_NAMESPACE}\" --set \"Release.HelmReleaseName=${RELEASE_NAME}\" --name \"${RELEASE_NAME}-$component\" $DIR/../helm/$component"
  helm install --namespace "${PLT_NAMESPACE}" --set "Release.HelmReleaseName=${RELEASE_NAME}"  --name "${RELEASE_NAME}-$component" $DIR/$component
  else
  echo "helm install -f $OVERRIDEYAML --namespace \"${PLT_NAMESPACE}\" --set \"Release.HelmReleaseName=${RELEASE_NAME}\"  --name \"${RELEASE_NAME}-$component\" $DIR/../helm/$component"
  helm install -f $OVERRIDEYAML --namespace "${PLT_NAMESPACE}" --set "Release.HelmReleaseName=${RELEASE_NAME}"  --name "${RELEASE_NAME}-$component" $DIR/$component
  fi
done
