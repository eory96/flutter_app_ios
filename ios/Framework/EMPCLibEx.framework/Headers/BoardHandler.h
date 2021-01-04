//
//  BoardHandler.h
//  EMPCLibEx
//
//  Created by neotechsoft on 2020/01/13.
//  Copyright © 2020 neotechsoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN



@protocol BoardHandlerDelegate<NSObject>
@optional

//- (void)onPermissionAlarm:(BOOL)admin share:(BOOL)share draw:(BOOL)draw web:(BOOL)web;
- (void)onChangedTool;

@end


@interface BoardHandler : NSObject

+ (BoardHandler *)sharedInstance;

@property(assign) id <BoardHandlerDelegate> delegateEx;

- (void)setDelegate:(id)delegate;

- (id)boardView;

- (void)initBoard;
- (void)relaseBoard;

- (void)setMakingImage:(CGImageRef)image;


- (BOOL)fileSave:(NSString *)filename;
- (BOOL)fileSaveToAlbum;

- (BOOL)fileOpen:(NSString *)filename;
- (BOOL)fileOpen:(NSString*)title localFilePath:(NSString*)localFilePath;

- (BOOL)setPenStyle:(int)style width:(int)width color:(UIColor *)color;
- (BOOL)setFigureStyle:(int)style width:(int)width color:(UIColor *)color;
- (BOOL)setEraserStyle:(int)style;
- (BOOL)setDocToolEx:(int)tool;
- (int)getDocToolEx;

- (void)setProductID:(int)productID productSubID:(int)productSubID;
- (void)setUserInfo:(NSString *)userID alias:(NSString *)alias;
- (void)initFileServer:(NSString *)folder;
- (void)setRoomInfo:(int)topRoom subRoom:(int)subRoom;
- (void)createClassType:(int)val1 val2:(BOOL)val2 val3:(BOOL)val3;
- (void)setAuthInfo:(BOOL)open draw:(BOOL)draw page:(BOOL)page;
- (void)setAuthInfo_FileOpen:(BOOL)open;
- (void)showDocList:(BOOL)show;
- (void)toggleShowDocList;

- (BOOL)hasOpenAuth;
- (BOOL)hasDrawAuth;
- (BOOL)hasDrawAuth:(NSString*)userID;
- (BOOL)hasPageAuth;
- (BOOL)hasWebAuth;

- (void)toggleDocDrawAuth:(NSString*)userID;



@end

NS_ASSUME_NONNULL_END
