//
//  ACRRegistration
//  ACRRegistration.mm
//
//  Copyright © 2017 Microsoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ACRRegistration.h"
#import "ACRColumnView.h"
#import "ACRColumnSetView.h"
#import "ACRImageRenderer.h"
#import "ACRImageSetRenderer.h"
#import "ACRTextBlockRenderer.h"
#import "ACRInputRenderer.h"
#import "ACRInputToggleRenderer.h"
#import "ACRInputChoiceSetRenderer.h"
#import "ACRInputDateRenderer.h"
#import "ACRInputTimeRenderer.h"
#import "ACRInputNumberRenderer.h"
#import "ACRFactSetRenderer.h"
#import "ACRContainerRenderer.h"
#import "ACRColumnSetRenderer.h"
#import "ACRColumnRenderer.h"
#import "ACRActionOpenURLRenderer.h"
#import "ACRActionShowCardRenderer.h"
#import "ACRActionSubmitRenderer.h"
#import "ACRCustomRenderer.h"
#import "BaseCardElement.h"
#import "HostConfig.h"

using namespace AdaptiveCards;

@implementation ACRRegistration
{
    NSMutableDictionary *typeToRendererDict;
    NSMutableDictionary *actionRendererDict;
}

- (instancetype) init
{
    self = [super init];
    if(self)
    {
        typeToRendererDict =
            [[NSMutableDictionary alloc] initWithObjectsAndKeys:
             [ACRImageRenderer getInstance],      [NSNumber numberWithInt:(int)[ACRImageRenderer elemType]],
             [ACRImageSetRenderer getInstance],   [NSNumber numberWithInt:(int)[ACRImageSetRenderer elemType]],
             [ACRTextBlockRenderer getInstance],  [NSNumber numberWithInt:(int)[ACRTextBlockRenderer elemType]],
             [ACRInputRenderer     getInstance],  [NSNumber numberWithInt:(int)[ACRInputRenderer elemType]],
             [ACRInputToggleRenderer getInstance],[NSNumber numberWithInt:(int)[ACRInputToggleRenderer elemType]],
             [ACRInputChoiceSetRenderer getInstance],[NSNumber numberWithInt:(int)[ACRInputChoiceSetRenderer elemType]],
             [ACRInputDateRenderer getInstance],  [NSNumber numberWithInt:(int)[ACRInputDateRenderer elemType]],
             [ACRInputTimeRenderer getInstance],  [NSNumber numberWithInt:(int)[ACRInputTimeRenderer elemType]],
             [ACRInputNumberRenderer getInstance],[NSNumber numberWithInt:(int)[ACRInputNumberRenderer elemType]],
             [ACRFactSetRenderer getInstance],    [NSNumber numberWithInt:(int)[ACRFactSetRenderer elemType]],
             [ACRContainerRenderer getInstance],  [NSNumber numberWithInt:(int)[ACRContainerRenderer elemType]],
             [ACRColumnSetRenderer getInstance],  [NSNumber numberWithInt:(int)[ACRColumnSetRenderer elemType]],
             [ACRColumnRenderer getInstance],     [NSNumber numberWithInt:(int)[ACRColumnRenderer elemType]],
             [ACRCustomRenderer getInstance],     [NSNumber numberWithInt:(int)[ACRCustomRenderer elemType]],
             nil];
        actionRendererDict =
            [[NSMutableDictionary alloc] initWithObjectsAndKeys:
             [ACRActionOpenURLRenderer  getInstance], [NSNumber numberWithInt:(int)ActionType::OpenUrl],
             [ACRActionShowCardRenderer getInstance], [NSNumber numberWithInt:(int)ActionType::ShowCard],
             [ACRActionSubmitRenderer   getInstance], [NSNumber numberWithInt:(int)ActionType::Submit],
             nil];
    }
    return self;
}

+ (ACRRegistration *) getInstance
{
    static ACRRegistration *singletonInstance = nil;
    static dispatch_once_t predicate;
    dispatch_once(&predicate, ^{singletonInstance = [[self alloc] init];});
    return singletonInstance;
}

- (ACRBaseCardElementRenderer *) getRenderer:(NSNumber *)cardElementType
{
    return [typeToRendererDict objectForKey:cardElementType];
}

- (ACRBaseActionElementRenderer *) getActionRenderer:(NSNumber *)cardElementType
{
    return [actionRendererDict objectForKey:cardElementType];
}

- (void) setActionRenderer:(ACRBaseActionElementRenderer *)renderer cardElementType:(NSNumber *)cardElementType
{
    [actionRendererDict setObject:renderer forKey:cardElementType];
}

- (void) setBaseCardElementRenderer:(ACRBaseCardElementRenderer *)renderer cardElementType:(ACRCardElementType)cardElementType
{
    [typeToRendererDict setObject:renderer forKey:[NSNumber numberWithInteger:cardElementType]];
}

- (void) setCustomElementParser:(NSObject<ACOIBaseCardElementParser> *)customElementParser
{
    ACRCustomRenderer *customRenderer = [ACRCustomRenderer getInstance];
    customRenderer.customElementParser = customElementParser;
}

@end
