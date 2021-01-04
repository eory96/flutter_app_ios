//
//  UserInfoEx.h
//  EMPCLibEx
//
//  Created by neotechsoft on 2020/03/19.
//  Copyright © 2020 neotechsoft. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface UserInfoEx : NSObject
- (void)setRoomNo:(int)roomNo;
- (int)getRoomNo;

- (void)setUserID:(NSString*)userID;
- (NSString*)getUserID;

- (void)setAlias:(NSString*)alias;
- (NSString*)getAlias;

- (void)setUserType:(int)userType;
- (int)getUserType;

- (void)setLoginTime:(NSString*)time;
- (NSString*)getLoginTime;

@end

NS_ASSUME_NONNULL_END
