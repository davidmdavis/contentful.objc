//
//  UIImageView+CDAAsset.h
//  ContentfulSDK
//
//  Created by Boris Bügling on 13/03/14.
//
//

#import <UIKit/UIKit.h>

@class CDAAsset;

/**
 Convenience category on `UIImageView` which allows asynchronously setting its image from a given
 Asset. 
 
 Attempting non-sensical operations like using an Asset pointing to a video will throw exceptions.
 */
@interface UIImageView (CDAAsset)

/**
 *  Set this image view's image to the image file retrieved from the given Asset. 
 *
 *  This will happen asynchronously in the background.
 *
 *  @param asset An Asset pointing to an image.
 *  @exception NSIllegalArgumentException If the Asset is pointing to an image.
 */
-(void)cda_setImageWithAsset:(CDAAsset*)asset;

/**
 *  Set this image view's image to the image file retrieved from the given Asset.
 *
 *  This will happen asynchronously in the background.
 *
 *  @param asset An Asset pointing to an image.
 *  @param size             The desired size of the image. It will be resized by the server.
 *  @exception NSIllegalArgumentException If the Asset is pointing to an image.
 */
-(void)cda_setImageWithAsset:(CDAAsset*)asset size:(CGSize)size;

/**
 *  Set this image view's image to the image file retrieved from the given Asset. 
 *
 *  This will happen asynchronously in the background. Until the image is loaded, 
 *  the `placeholderImage` is displayed.
 *
 *  @param asset            An Asset pointing to an image.
 *  @param placeholderImage An alternative image which will be displayed until `asset` is loaded.
 *  @exception NSIllegalArgumentException If the Asset is pointing to an image.
 */
-(void)cda_setImageWithAsset:(CDAAsset *)asset placeholderImage:(UIImage *)placeholderImage;

/**
 *  Set this image view's image to the image file retrieved from the given Asset.
 *
 *  This will happen asynchronously in the background. Until the image is loaded,
 *  the `placeholderImage` is displayed.
 *
 *  @param asset            An Asset pointing to an image.
 *  @param size             The desired size of the image. It will be resized by the server.
 *  @param placeholderImage An alternative image which will be displayed until `asset` is loaded.
 *  @exception NSIllegalArgumentException If the Asset is pointing to an image.
 */
-(void)cda_setImageWithAsset:(CDAAsset *)asset
                        size:(CGSize)size
            placeholderImage:(UIImage *)placeholderImage;

/** @name Use Offline Caching */

/** Enable automatic disk caching of any image loaded by one of the Asset category methods. */
@property (nonatomic) BOOL offlineCaching_cda;

@end
