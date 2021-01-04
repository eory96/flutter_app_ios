//
//  AudioLib.h
//  EMPCLib
//
//  Created by apple on 2018. 7. 2..
//  Copyright © 2018년 neotechsoft. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AudioLib : NSObject

+ (AudioLib *)sharedInstance;

- (BOOL)start;
- (void)stop;

- (BOOL)isSpeakerOn;
- (void)setSpeakerOn:(BOOL)on;

- (BOOL)hasAudioAuth;
- (BOOL)hasAudioAuth:(NSString*)userID;

- (void)toggleAudioAuth:(NSString*)userID;

- (void)routeChanged;
- (void)restartAudio;


@end
