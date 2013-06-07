//
//  NSObject+SafeObject.h
//
//  Created by Max Winde on 15.05.13.
//  Copyright (c) 2013 Max Winde. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (Expectation)

- (id)nilUnlessKindOfClass:(Class)aClass;
- (id)nilUnlessRespondsToSelector:(SEL)selector;
- (id)nilUnlessConformsToProtocol:(Protocol *)aProtocol;

- (id)unless:(NSObject *)object isKindOfClass:(Class)aClass;
- (id)unless:(NSObject *)object respondsToSelector:(SEL)selector;
- (id)unless:(NSObject *)object conformsToProtocol:(Protocol *)aProtocol;

- (id)ifIsKindOfClass:(Class)aClass;
- (id)IfRespondsToSelector:(SEL)selector;
- (id)IfConformsToProtocol:(Protocol *)aProtocol;

@end
