# NSObject+Expectation

### Simple object verification that does not clutter your code.

We've all been there: you get some `NSDictionary` from some JSON deserialization, you expect it to be an `NSString`:

```
NSString *middleName = dictionaryFromJSON[@"middle_name"];
```

Everything seems fine until you discover that the middleName is optional and sometimes `null`. And suddenly your middleName contains `NSNull` instead of `NSString` and your App crashes because you tried to call `length` on your `NSNull` object. So you end up writing something like this:

```
NSString *middleName = dictionaryFromJSON[@"middle_name"];
if (![middleName isKindOfClass:[NSString class]) {
	middleName = nil;
}
```

Lots of ugly code for a simple stupid check. Meet NSObject+Expectation:

```
NSString *middleName = [dictionaryFromJSON[@"middle_name"] nilUnlessIsKindOfClass:[NSString class]];
```

`[object nilUnlessIsKindOfClass:aClass]` returns `object` if it is indeed an object of `aClass`. Otherwise it returns `nil`.

But there is even a little bit more. Take this example:

```
NSInteger someIntegerValue = [dictionary[@"someIntegerValue"] integerValue];
```

We already learnt that we can make this crash proof by using our little helper:

```
NSInteger someIntegerValue = [[dictionary[@"someIntegerValue"] ifIsKindOfClass:[NSNumber class]] integerValue];
```

But actually we don't care if our object is an `NSNumber`. We are fine, as long a the object won't crash if we call `integerValue` on it. There is an selector for that:

```
NSInteger someIntegerValue = [[dictionary[@"someIntegerValue"] nilUnlessRespondsToSelector:@selector(integerValue)] integerValue];
```

Finally there is one last method so you are completely covered:

```
id<MyFancyProtocol> aObject = [dictionary[@"fancyObject"] nilUnlessConformsToProtocol:@protocol(MyFancyProtocol)];
```

### optional Methods in Protocols

The `nilUnlessRespondsToSelector:` can become handy when calling optional methods of a protocol. How often did you write code like this:

```
if ([self.delegate respondsToSelector:@selector(shouldAbortDownloading)]) {
	return [self.delegate shouldAbortDownloading];
} else {
	return NO;
}
```

This might become a one-liner like this:
```
return [[self.delegate nilUnlessRespondsToSelector:@selector(shouldAbortDownloading)] shouldAbortDownloading];
```

### Default values

If you need a default value instead of nil we have something for you to:

```
NSInteger theAnswer =  [[@(42) unless:alternativeAnswer respondsToSelector:@selector(integerValue)] integerValue];
```

When alternativeAnswer responds to the integerValue selector it will return alternativeAnswer otherwise @(42).

Ther methods `unless:isKindOfClass:` and `unless:conformsToProtocol` are available to.

License: BSD
