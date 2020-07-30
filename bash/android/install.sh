#!/bin/bash
NODEJS_VERSION="8"
IONIC_VERSION="4.2.1"
ANDROID_SDK_VERSION="3859397"
ANDROID_HOME="/opt/android-sdk"
ANDROID_BUILD_TOOLS_VERSION="26.0.0"

# For nodejs
apt-get update \
    && apt-get install -y \
       build-essential \
       curl \
       git \
    && curl -sL https://deb.nodesource.com/setup_${NODEJS_VERSION}.x | bash - \
    && apt-get update \
    && apt-get install -y nodejs

# For android sdk
apt-get update \
    && apt-get install -y \
       openjdk-8-jre \
       openjdk-8-jdk \
       unzip \
       gradle \
    && cd /tmp \
    && curl -fSLk https://dl.google.com/android/repository/sdk-tools-linux-${ANDROID_SDK_VERSION}.zip -o sdk-tools-linux-${ANDROID_SDK_VERSION}.zip \
    && unzip sdk-tools-linux-${ANDROID_SDK_VERSION}.zip \
    && mkdir /opt/android-sdk \
    && mv tools /opt/android-sdk \
    && (while sleep 3; do echo "y"; done) | $ANDROID_HOME/tools/bin/sdkmanager --licenses \
    && $ANDROID_HOME/tools/bin/sdkmanager "platform-tools" \
    && $ANDROID_HOME/tools/bin/sdkmanager "build-tools;${ANDROID_BUILD_TOOLS_VERSION}" \
    && apt-get autoremove -y \
    && rm -rf /tmp/sdk-tools-linux-${ANDROID_SDK_VERSION}.zip 

