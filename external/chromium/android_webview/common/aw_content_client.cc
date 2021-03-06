// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "android_webview/common/aw_content_client.h"

#include "base/basictypes.h"
#include "ui/base/l10n/l10n_util.h"
#include "ui/base/resource/resource_bundle.h"
#include "webkit/user_agent/user_agent_util.h"

namespace android_webview {

std::string AwContentClient::GetProduct() const {
  // "Version/4.0" had been hardcoded in the legacy WebView.
  return std::string("Version/4.0");
}

std::string AwContentClient::GetUserAgent() const {
  return webkit_glue::BuildUserAgentFromProduct(GetProduct());
}

string16 AwContentClient::GetLocalizedString(int message_id) const {
  // TODO(boliu): Used only by WebKit, so only bundle those resources for
  // Android WebView.
  return l10n_util::GetStringUTF16(message_id);
}

base::StringPiece AwContentClient::GetDataResource(
    int resource_id,
    ui::ScaleFactor scale_factor) const {
  // TODO(boliu): Used only by WebKit, so only bundle those resources for
  // Android WebView.
  return ResourceBundle::GetSharedInstance().GetRawDataResourceForScale(
      resource_id, scale_factor);
}

}  // namespace android_webview
