//
//  MNKRouting.h
//  MapNavigationKit
//
//  Created by Michal Zelinka on 10/08/2019.
//  Copyright © 2019 Michal Zelinka. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapNavigationKit/MNKNavigation.h>

NS_ASSUME_NONNULL_BEGIN


#pragma mark - Map Routing info


@interface MNKRoutingInfo: NSObject

@property (nonatomic, strong) MNKRouteStep *step;
@property (atomic) double stepProgress;
@property (atomic) BOOL outOfPath;
@property (atomic) CLLocationDistance distanceFromPath;

@end


#pragma mark - Map Routing delegate


@protocol MNKRoutingDelegate <NSObject>

@optional
- (void)routingDidStart;
- (void)routingRouteDidUpdate:(MNKRoute *)route;
- (void)routingInfoDidUpdate:(MNKRoutingInfo *)info;
- (void)routingDidStop;

@end


#pragma mark - Map Routing provider


@interface MNKRouting : NSObject

@property (nonatomic, weak, nullable) id<MNKRoutingDelegate> delegate;
@property (nonatomic, strong, nullable) MNKRoutingInfo *currentInfo;

- (void)startWithRoute:(MNKRoute *)route NS_SWIFT_NAME(start(with:));
- (void)stop;

- (void)priv_updateLocation:(CLLocation *)userLocation;

@end


NS_ASSUME_NONNULL_END
