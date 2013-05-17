# NSObject+Expectation

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
NSString *middleName = [dictionaryFromJSON[@"middle_name"] ifIsKindOfClass:[NSString class]];
```

`[object ifIsKindOfClass:aClass]` returns `object` is indeed an object of `aClass` and otherwise nil.

But there is even a little bit more. Take this example:

```
NSInteger someIntegerValue = [dictionary[@"someIntegerValue"] integerValue];
```

We allready learnt that we can make this crash proof by using our little helper:

```
NSInteger someIntegerValue = [[dictionary[@"someIntegerValue"] ifIsKindOfClass:[NSNumber class]] integerValue];
```

But actually we don't care if our object is an `NSNumber`. We are completly fine, as long a the object won't crash if we call `integerValue` on it. There is an selector for that:

```
NSInteger someIntegerValue = [[dictionary[@"someIntegerValue"] ifRespondsToSelector:@selector(integerValue)] integerValue];
```

Finally there is one last method so you are completly covered:

```
id<MyFancyProtocol> aObject = [dictionary[@"fancyObject"] ifConformsToProtocol:@protocol(MyFancyProtocol)];
```

License: BSD
