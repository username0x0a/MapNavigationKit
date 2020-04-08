# MapNavigationKit

**MapNavigationKit** is a tiny framework expanding the capabilities of routing that `MapKit` already has, albeit not that prominently, exposing some additional information you can use to flawlessly build a navigation app on top of `MapKit`.

Although the data are primarily for first-hand use with `MapKit`, it can be easily used with other Map UI frameworks, too – `MapBox`, `GoogleMaps` and other SDKs provide a way to build a custom polyline and route objects, with the benefit of using data fetched by this wrapper over the default (and probably payed) alternative provided by the specific Map SDK.

## Getting the framework

### Installing via CocoaPods

Simply add a `MapNavigationKit` pod to your `Podfile`. Then run `pod update` to fetch the framework automatically.

### Getting the framework from GitHub

You can grab a released compiled framework package or its source code on [GitHub](https://github.com/username0x0a/MapNavigationKit). Check out the repository or grab it from the _Releases_ section.

## Development Requirements

All development requirements are actually recommendations as it reflects the environment we use to develop and distribute the code.

- Xcode 11.0+ (recommended)
- macOS 10.10+ SDK (recommended)
- iOS 10.0+ SDK (recommended)
- tvOS 10.0+ SDK (recommended)
- _Objective-C_ or _Swift_ project

## Production Deployment

Deployment requirements determine the minimal environments compatible with the framework when you distribute it with your project.

- macOS 10.10+ target (_macOS framework_)
- iOS 10.0+ target (_iOS framework_)
- tvOS 10.0+ target (_tvOS framework_)

## Installation

- get the framework package
- unpack and add to your project
- link it as a dynamic framework (embedded binary) in your project settings

## Quick Usage Introduction

This quick example shows how to use the framework to fetch a representative route.

### Requirements

- _walking_ route
- starting at _Big Ben_ in London
- finishing at _Greenwich Observatory_ in London

### Code

```swift
// Big Ben
let srcLocation = CLLocation(latitude: 51.5003646652, longitude: -0.1214328476)

// Greenwich Observatory
let dstLocation = CLLocation(latitude: 51.4733514399, longitude: -0.00088499646)

let query = MNKRouteQuery(type: .walking, source: srcLocation, destination: dstLocation)

MNKRouteFetcher.fetchRoute(query: query) { (route) in
	guard let route = route else { return }
	let steps = route.steps
		.filter { $0.localizedInstructions?.isEmpty == false }
		.map { "- After \(Int($0.nextManeuverDistance))m: \($0.localizedInstructions!)" }
		.joined(separator: "\n")
	print(steps)
}
```

### Example output

```
- After 329m: Turn left onto Saint Margaret Street
- After 66m: Keep left onto Saint Margaret Street
- After 641m: At the roundabout, take the first exit onto Lambeth Bridge
- After 326m: At the roundabout, take the second exit onto Lambeth Road
- After 957m: Turn left onto A302
- After 133m: Turn right onto Westminster Bridge Road
- After 471m: Continue onto London Road
- After 292m: Turn left onto Elephant and Castle
- After 798m: Keep right onto New Kent Road
- After 602m: Continue onto Old Kent Road
- After 6459m: Turn left onto General Wolfe Road
- After 82m: Turn right onto Chesterfield Walk
- After 83m: Turn left onto Chesterfield Walk
- After 16m: Prepare to park your car
- After 0m: Take a right
- After 50m: Take a right
- After 37m: The destination is on your left
```

*MapNavigationKit* is very easily testable using _Swift Playgrounds_.

## Basic Classes

Class                    | Description
:------------------------|:---------------------
**`MNKRoute`**           | Basic `Route` instance
**`MNKRouteStep`**       | Particular `Route` step
**`MNKRouteQuery`**      | Query instance used for fetching
**`MNKRouteFetcher`**    | Fetching worker
**`MNKRouting`**         | Routing provider
**`MNKRoutingInfo`**     | Current, displayable routing info

## License

This project is licensed under the terms of the MIT license. See the **LICENSE** file for details.
