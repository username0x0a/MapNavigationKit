//
//  MNKNavigation.h
//  MapNavigationKit
//
//  Created by Michal Zelinka on 02/11/2018.
//  Copyright © 2018 Michal Zelinka. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MKDirectionsResponse.h>


NS_ASSUME_NONNULL_BEGIN


#pragma mark - Definitions


typedef NS_ENUM(NSInteger, MNKRouteType)
{
	MNKRouteTypeWalking = 0,
	MNKRouteTypeCar,
};

typedef NS_ENUM(NSInteger, MNKRouteManeuverType)
{
	MNKRouteManeuverTypeNone = 0,
	MNKRouteManeuverTypeStart,
	MNKRouteManeuverTypeEasyLeft,
	MNKRouteManeuverTypeEasyRight,
	MNKRouteManeuverTypeVia,
	MNKRouteManeuverTypeKeepLeft,
	MNKRouteManeuverTypeKeepRight,
	MNKRouteManeuverTypeLeft,
	MNKRouteManeuverTypeOutOfRoute,
	MNKRouteManeuverTypeRight,
	MNKRouteManeuverTypeSharpLeft,
	MNKRouteManeuverTypeSharpRight,
	MNKRouteManeuverTypeStraight,
	MNKRouteManeuverTypeUTurn,
	MNKRouteManeuverTypeEnterFerry,
	MNKRouteManeuverTypeChangeFerry,
	MNKRouteManeuverTypeExitFerry,
	MNKRouteManeuverTypeEnterRamp,
	MNKRouteManeuverTypeExitRamp,
	MNKRouteManeuverTypeStateBoundary,
	MNKRouteManeuverTypeFollow,
	MNKRouteManeuverTypeMotorway,
	MNKRouteManeuverTypeChangeMotorway,
	MNKRouteManeuverTypeTunnel,
	MNKRouteManeuverTypeEnterRoundabout,
	MNKRouteManeuverTypeExitRoundabout,
	MNKRouteManeuverTypeExit,
	MNKRouteManeuverTypeEnd,
	MNKRouteManeuverTypeEndOnLeft,
	MNKRouteManeuverTypeEndOnRight,
};


#pragma mark - Navigation step


@interface MNKRouteStep : NSObject

@property (atomic, readonly) NSUInteger order;
@property (nonatomic, readonly, copy, nullable) NSString *destinationTitle;
@property (nonatomic, readonly, copy) NSArray<CLLocation *> *locations;

@property (atomic, readonly) CLLocationDistance remainingDistance;
@property (atomic, readonly) NSTimeInterval remainingTime;
@property (atomic, readonly) MNKRouteManeuverType nextManeuver;
@property (nonatomic, readonly, copy, nullable) NSString *nextManeuverString;
@property (atomic, readonly) CLLocationDistance nextManeuverDistance;
@property (atomic, readonly) NSTimeInterval nextManeuverTime;
@property (nonatomic, readonly, copy, nullable) NSString *localizedInstructions;

+ (instancetype)new  UNAVAILABLE_ATTRIBUTE;
- (instancetype)init UNAVAILABLE_ATTRIBUTE;

@end


#pragma mark - Navigation route


@interface MNKRoute : NSObject

@property (atomic, readonly) MNKRouteType type;
@property (nonatomic, readonly) MKRoute *backingRoute;

@property (nonatomic, copy, readonly) NSString *name;
@property (nonatomic, copy, nullable) NSString *sourceLocationName;
@property (nonatomic, copy, nullable) NSString *destinationLocationName;

@property (nonatomic, readonly) CLLocation *sourceLocation;
@property (nonatomic, readonly) CLLocation *destinationLocation;

@property (nonatomic, readonly) NSArray<MNKRouteStep *> *steps;

@property (atomic, readonly) NSTimeInterval duration;
@property (atomic, readonly) CLLocationDistance distance;
@property (nonatomic, readonly) NSArray<CLLocation *> *locations;

@property (nonatomic, readonly) MKPolyline *mkPolyline;

+ (instancetype)new  UNAVAILABLE_ATTRIBUTE;
- (instancetype)init UNAVAILABLE_ATTRIBUTE;

+ (nullable instancetype)routeWithMKRoute:(MKRoute *)route;

@end


#pragma mark - Navigation query


@interface MNKRouteQuery : NSObject

@property (atomic) MNKRouteType type;
@property (nonatomic, copy) CLLocation *sourceLocation;
@property (nonatomic, copy) CLLocation *destinationLocation;

+ (instancetype)new  UNAVAILABLE_ATTRIBUTE;
- (instancetype)init UNAVAILABLE_ATTRIBUTE;

+ (instancetype)queryWithType:(MNKRouteType)type
               sourceLocation:(CLLocation *)sourceLocation
          destinationLocation:(CLLocation *)destinationLocation
NS_SWIFT_UNAVAILABLE("Use init(...) instead.");

- (instancetype)initWithType:(MNKRouteType)type
              sourceLocation:(CLLocation *)sourceLocation
         destinationLocation:(CLLocation *)destinationLocation
NS_SWIFT_NAME(init(type:source:destination:));

@end


#pragma mark - Navigation fetcher


@interface MNKRouteFetcher : NSObject

+ (instancetype)new  UNAVAILABLE_ATTRIBUTE;
- (instancetype)init UNAVAILABLE_ATTRIBUTE;

+ (void)fetchRouteForQuery:(MNKRouteQuery *)query
                completion:(void (^)(MNKRoute *_Nullable route))completion
NS_SWIFT_NAME(fetchRoute(query:completion:));

@end


NS_ASSUME_NONNULL_END
