//
//  ACRAggregateTarget
//  ACRAggregateTarget.h
//
//  Copyright © 2018 Microsoft. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ACRIContentHoldingView.h"
#import "SharedAdaptiveCard.h"
#import "HostConfig.h"
#import "ACRLongPressGestureRecognizerEventHandler.h"
#import "ACRView.h"

@interface ACRAggregateTarget:NSObject<ACRSelectActionDelegate>

- (instancetype)initWithActionElement:(ACOBaseActionElement *)actionElement rootView:(ACRView *)rootView;

- (IBAction)send:(UIButton *)sender;

- (void)doSelectAction;

@end
