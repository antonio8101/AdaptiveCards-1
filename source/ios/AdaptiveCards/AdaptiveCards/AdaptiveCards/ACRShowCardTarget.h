//
//  ACRShowCardTarget
//  ACRShowCardTarget.h
//
//  Copyright © 2017 Microsoft. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ACRIContentHoldingView.h"
#import "SharedAdaptiveCard.h"
#import "ACRLongPressGestureRecognizerEventHandler.h"
#import "ACRView.h"

@interface ACRShowCardTarget:NSObject<ACRSelectActionDelegate>

- (instancetype)initWithAdaptiveCard:(std::shared_ptr<AdaptiveCards::AdaptiveCard> const &)adaptiveCard 
                              config:(ACOHostConfig *)config
                           superview:(UIView<ACRIContentHoldingView> *)superview
                            rootView:(ACRView *)rootView;

// show or hide a showCard UIView. If the UIView is not created already, it will be created and shown
// else, it toggles the visibility
- (IBAction)toggleVisibilityOfShowCard;
@end
