//
//  ServerHandler.h
//  EMPCLibEx
//
//  Created by 네오텍소프트 on 10/12/2019.
//  Copyright © 2019 neotechsoft. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

enum conf_type_ex {
    conf_doc_ex,
    conf_web_ex,
    conf_video_ex,
};


typedef enum : NSInteger {
    MSG_CHANGE_VIEW_TYPE = 80,
    MSG_CHANGE_PERMISSION = 90,
    MSG_CHANGE_PERMISSION_DETAIL = 95,

    MSG_INITIAL_ROOM = 99,
    MSG_REMOTE_ENTER_ROOM = 100,
    MSG_REMOTE_EXIT_ROOM = 101,
    MSG_OVERLAPPED_USER_ID = 102,
    MSG_KICK_OUT = 103,
    MSG_CHANGE_ENLARGE = 110,
    MSG_DISCONNECTED_EVENTSERVER = 111,
    MSG_DISCONNECTED_RELAYSERVER = 112,

    MSG_CLIENT_RQST_LECTURE_INFO = 120,
    MSG_CLIENT_RESP_LECTURE_INFO = 121,

    MSG_CLIENT_RQST_CUSTOM_INFO = 130,            //사용자정의 클라이언트 명령 요청
    MSG_CLIENT_RESP_CUSTOM_INFO = 131,            //사용자정의 클라이언트 명령 응답

    MSG_INITIAL_DOCS = 150,

} SERVER_EVENT;


typedef enum : NSInteger {
    PERMISSION_TYPE_OWNER = 0,
    PERMISSION_TYPE_SPEACKER = 1,
    PERMISSION_TYPE_DESKTOPSHARE = 2,
    PERMISSION_TYPE_VIDEO = 3,
    PERMISSION_TYPE_AUDIO = 4,
    PERMISSION_TYPE_DOC = 5,
    PERMISSION_TYPE_CHAT = 6,
    PERMISSION_TYPE_CHAT_ONOFF = 7,

} PERMISSION_TYPE;


@protocol ServerDelegate<NSObject>
@optional

- (void)onMainServerEvent:(NSInteger)what arg1:(NSInteger)arg1 arg2:(NSString*)arg2;
@end

@interface ServerHandler : NSObject

+ (ServerHandler *)sharedInstance;

- (void)setDelegate:(id)delegate;
- (void)applicationEnterBackground:(BOOL)on;


- (void)setServerInfo:(NSString*)productID ip:(NSString*)ip mainPort:(int)mainPort filePort:(int)filePort;

- (NSInteger)login:(NSString *)userID passwd:(NSString *)passwd alias:(NSString *)alias ownerID:(NSString *)ownerID company:(NSString *)company;
- (void)logout;

- (BOOL)enterRoom:(NSInteger)topRoomNo subRoomNo:(NSInteger)subRoomNo;
- (NSInteger)enterRoom:(NSString *)userID meetID:(NSString *)meetID roomTitle:(NSString *)roomTitle maxUser:(int)maxUser;
- (BOOL)enterSubRoomNotify;
- (void)exitRoom;

- (NSString*)getProductID;
- (int)getProductSubID;

- (NSInteger)getTopRoomNo;
- (NSInteger)getRoomNo;

- (int)getViewType;
- (void)setViewType:(int)type;

- (void)grantAdmin:(NSString*)userID;
- (void)toggleSpeackerAuth:(NSString*)userID;

- (NSString*)getUserID;
- (NSString*)getAlias;
- (NSInteger)getUserKey;

- (BOOL)isOwner;
- (BOOL)isOwner:(NSString*)userID;

- (BOOL)isAdmin;
- (BOOL)isAdmin:(NSString*)userID;

- (int)getRoomUserCount;
- (id)getRoomUserAt:(int)index;
- (id)getRoomUser:(NSString*)userID;

@end

NS_ASSUME_NONNULL_END
