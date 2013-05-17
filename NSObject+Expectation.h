//
//  NSObject+SafeObject.h
//  Trivago
//
//  Created by Max Winde on 15.05.13.
//  Copyright (c) 2013 nxtbgthng GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (Expectation)

- (id)ifIsKindOfClass:(Class)aClass;
- (id)ifRespondsToSelector:(SEL)selector;
- (id)ifConformsToProtocol:(Protocol *)aProtocol;

@end
