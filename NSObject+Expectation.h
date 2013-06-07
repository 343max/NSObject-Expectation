//
//  NSObject+SafeObject.h
//
//  Created by Max Winde on 15.05.13.
//  Copyright (c) 2013 Max Winde. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (Expectation)

/**
 Returns self if it is kind of class aClass or nil otherwise
 @return self or nil
 */
- (id)nilUnlessKindOfClass:(Class)aClass;

/**
 Returns self if it responds to the given selector or nil otherwise
 @return self or nil
 */
- (id)nilUnlessRespondsToSelector:(SEL)selector;

/**
 Returns self if it conforms to the given protocol or nil otherwise
 @return self or nil
 */
- (id)nilUnlessConformsToProtocol:(Protocol *)aProtocol;


#pragma mark - Default Value

/**
 Returns object if it is kind of class aClass or self otherwise
 @return object or self
 */
- (id)unless:(NSObject *)object isKindOfClass:(Class)aClass;

/**
 Returns object if it responds to the given selector or nil otherwise
 @return object or self
 */
- (id)unless:(NSObject *)object respondsToSelector:(SEL)selector;

/**
 Returns objecy if it conforms to the given protocol or nil otherwise
 @return object or self
 */
- (id)unless:(NSObject *)object conformsToProtocol:(Protocol *)aProtocol;


#pragma mark - Deprectated

/**
 Returns self if it is kind of class aClass or nil otherwise
 @deprecated use nilUnlessKindOfClass: instead
 @return self or nil
 */
- (id)ifIsKindOfClass:(Class)aClass;

/**
 Returns self if it responds to the given selector or nil otherwise
 @deprecated use nilUnlessRespondsToSelector: instead
 @return self or nil
 */
- (id)IfRespondsToSelector:(SEL)selector;

/**
 Returns self if it conforms to the given protocol or nil otherwise
 @deprecated use nilUnlessConformsToProtocol: instead
 @return self or nil
 */
- (id)IfConformsToProtocol:(Protocol *)aProtocol;

@end
