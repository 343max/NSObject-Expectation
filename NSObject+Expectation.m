//
//  NSObject+SafeObject.m
//
//  Created by Max Winde on 15.05.13.
//  Copyright (c) 2013 Max Winde. All rights reserved.
//

#import "NSObject+Expectation.h"

@implementation NSObject (Expectation)

- (id)nilUnlessKindOfClass:(Class)aClass;
{
    return ([self isKindOfClass:aClass] ? self : nil);
}

- (id)nilUnlessRespondsToSelector:(SEL)selector;
{
    return ([self respondsToSelector:selector] ? self : nil);
}

- (id)nilUnlessConformsToProtocol:(Protocol *)aProtocol;
{
    return ([self conformsToProtocol:aProtocol] ? self : nil);
}

@end
