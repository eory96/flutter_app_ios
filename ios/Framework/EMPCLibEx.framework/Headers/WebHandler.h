//
//  WebHandler.h
//  EMPCLibEx
//
//  Created by neotechsoft on 2020/01/20.
//  Copyright © 2020 neotechsoft. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@protocol WebHandlerDelegate

- (void)webChangedUrl:(NSString*)url;

@end

@interface WebHandler : NSObject

+ (WebHandler *)sharedInstance;

- (void)setDelegate:(id)delegate;

- (id)webView;

- (void)initWeb;
- (void)relaseWeb;

- (void)setAuthInfo:(BOOL)ctrl;

- (void)goBack;
- (void)goForward;

- (void)goURL:(NSString *)url;
- (BOOL)shareWebPageCapture;


@end

NS_ASSUME_NONNULL_END
