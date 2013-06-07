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


#pragma mark - Default Values

- (id)unless:(NSObject *)object isKindOfClass:(Class)aClass;
{
    return ([object nilUnlessKindOfClass:aClass] ? object : self);
}

- (id)unless:(NSObject *)object respondsToSelector:(SEL)selector;
{
    return ([object nilUnlessRespondsToSelector:selector] ? object : self);
}

- (id)unless:(NSObject *)object conformsToProtocol:(Protocol *)aProtocol;
{
    return ([object nilUnlessConformsToProtocol:aProtocol] ? object : self);
}


#pragma mark - Deprecated

- (id)ifIsKindOfClass:(Class)aClass;
{
    return [self nilUnlessKindOfClass:aClass];
}

- (id)IfRespondsToSelector:(SEL)selector;
{
    return [self nilUnlessRespondsToSelector:selector];
}

- (id)IfConformsToProtocol:(Protocol *)aProtocol;
{
    return [self nilUnlessConformsToProtocol:aProtocol];
}

@end
