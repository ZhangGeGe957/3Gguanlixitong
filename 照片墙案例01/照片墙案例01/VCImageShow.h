//
//  VCImageShow.h
//  照片墙案例01
//
//  Created by 张佳乔 on 2021/6/13.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface VCImageShow : UIViewController

//图像视图的tag
@property (nonatomic, assign) NSUInteger imageTag;
//图像对象
@property (nonatomic ,retain) UIImage* image;
//图像视图对象
@property (nonatomic, retain) UIImageView* imageView;

@end

NS_ASSUME_NONNULL_END
