//
//  ACRToggleInputDataSource.mm
//  ACRToggleInputDataSource
//
//  Copyright © 2018 Microsoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ACRToggleInputDataSource.h"
#import "ToggleInput.h"
#import "ACRIBaseCardElementRenderer.h"
#import "HostConfig.h"

using namespace AdaptiveCards;

@implementation ACRToggleInputDataSource
{
    std::shared_ptr<ToggleInput> toggleInputDataSource;
    std::shared_ptr<HostConfig> config;
}

- (instancetype)initWithInputToggle:(std::shared_ptr<ToggleInput> const&)toggleInput
      WithHostConfig:(std::shared_ptr<HostConfig> const&)hostConfig
{
    self = [super init];
    if(self)
    {
        toggleInputDataSource = toggleInput;
        config = hostConfig;
        self.id = [[NSString alloc]initWithCString:toggleInputDataSource->GetId().c_str()
                                     encoding:NSUTF8StringEncoding];
        if(toggleInputDataSource->GetValue() == toggleInputDataSource->GetValueOn())
        {
            self.isSelected = YES;
        }
        self.valueOn  = [[NSString alloc]initWithCString:toggleInputDataSource->GetValueOn().c_str()
                                           encoding:NSUTF8StringEncoding];
        self.valueOff = [[NSString alloc]initWithCString:toggleInputDataSource->GetValueOff().c_str()
                                           encoding:NSUTF8StringEncoding];
    }
    return self;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return 1;
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    return nil;
}

- (NSString *)tableView:(UITableView *)tableView titleForFooterInSection:(NSInteger)section
{
    return nil;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *identifier = @"tabCellId";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identifier];
    if(!cell)
    {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault
                                      reuseIdentifier:identifier];
    }
    NSString *title = [NSString stringWithCString:toggleInputDataSource->GetTitle().c_str()
                                         encoding:NSUTF8StringEncoding];
    if(self.isSelected)
    {
        cell.accessoryType = UITableViewCellAccessoryCheckmark;
    }

    cell.textLabel.text = title;

    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [tableView cellForRowAtIndexPath:indexPath].selected = NO;
    if([tableView cellForRowAtIndexPath:indexPath].accessoryType ==
       UITableViewCellAccessoryCheckmark)
    {
        [tableView cellForRowAtIndexPath:indexPath].accessoryType = UITableViewCellAccessoryNone;
        self.isSelected = NO;
    }
    else
    {
        [tableView cellForRowAtIndexPath:indexPath].accessoryType =
        UITableViewCellAccessoryCheckmark;
        self.isSelected = YES;
    }
}

- (BOOL)validate:(NSError **)error
{
    // no need to validate
    return YES;
}

- (void)getInput:(NSMutableDictionary *)dictionary
{
    dictionary[self.id] = self.isSelected? self.valueOn : self.valueOff;
}

@end
