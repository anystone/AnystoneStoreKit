//
//  ASTStoreViewController.h
//  ASTStore
//
//  Created by Sean Kormilo on 11-03-07.
//  http://www.anystonetech.com

//  Voucher Sharing developed by Gregory Meach on 11-05-02.
//  http://meachware.com
//  Copyright (c) 2010 Gregory Meach, MeachWare.

//  Copyright (c) 2011 Anystone Technologies, Inc.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.


#import <UIKit/UIKit.h>
#import <GameKit/GameKit.h>
#import "ASTStoreController.h"

#define kTransmitKey    @"somethingVerySecretAndCoolGoesHere"
#define kReceiveKey     @"shouldBeASecret"
#define kSessionID      @"com.anystone.aststorekit"

// 0 = HIDE / 1 = SHOW
#define kAllowVoucherTransfers      1


@protocol ASTStoreViewControllerDelegate
- (void)astStoreViewControllerDidFinish:(UIViewController *)controller;
@end


@interface ASTStoreViewController : UIViewController
    <
    UITableViewDataSource, 
    UITableViewDelegate,
    GKPeerPickerControllerDelegate, 
    GKSessionDelegate,
    ASTStoreControllerDelegate,
    ASTStoreViewControllerDelegate
    >
{
    UIView *tableContainerView_;
    UITableView *tableView_;
    UITableViewCell *storeCell_;
  
    UIButton *restorePreviousPurchaseButton_;
    UILabel *connectingToStoreLabel_;
    UIActivityIndicatorView *connectingActivityIndicatorView_;
    
    id<ASTStoreViewControllerDelegate> delegate;
    BOOL isAniPad;
    
    GKSession *_session;
    NSString *_peerID;

}

@property (nonatomic, assign) id<ASTStoreViewControllerDelegate> delegate;

- (IBAction)restorePreviousPurchaseButtonPressed:(id)sender;
- (IBAction)launchConnect:(id)sender;

@property (retain) IBOutlet UIView *tableContainerView;
@property (retain) IBOutlet UITableView *tableView;
@property (retain) IBOutlet UITableViewCell *storeCell;

@property (nonatomic,retain) UIColor *cellBackgroundColor1;
@property (nonatomic,retain) UIColor *cellBackgroundColor2;

@end


