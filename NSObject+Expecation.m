//
//  NSObject+SafeObject.m
//  Trivago
//
//  Created by Max Winde on 15.05.13.
//  Copyright (c) 2013 nxtbgthng GmbH. All rights reserved.
//

#import "NSObject+Expectation.h"

@implementation NSObject (Expectation)

- (id)ifIsKindOfClass:(Class)aClass;
{
    return ([self isKindOfClass:aClass] ? self : nil);
}

- (id)ifRespondsToSelector:(SEL)selector;
{
    return ([self respondsToSelector:selector] ? self : nil);
}

- (id)ifConformsToProtocol:(Protocol *)aProtocol;
{
    return ([self conformsToProtocol:aProtocol] ? self : nil);
}

@end
