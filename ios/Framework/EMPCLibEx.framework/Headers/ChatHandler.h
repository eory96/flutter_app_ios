//
//  ChatHandler.h
//  EMPCLibEx
//
//  Created by neotechsoft on 2020/01/20.
//  Copyright © 2020 neotechsoft. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@protocol ChatHandlerDelegate

- (void)onReceivedText:(NSString*)text userID:(NSString*)userID;

@end

@interface ChatHandler : NSObject

+ (ChatHandler *)sharedInstance;

- (void)setDelegate:(id)delegate;

- (id)chatView;

- (void)initChat;
- (void)releaseChat;
- (void)setChatBubble:(CGImageRef)imageIn imageOut:(CGImageRef)imageOut;

- (void)sendText:(NSString *)text;


@end

NS_ASSUME_NONNULL_END
