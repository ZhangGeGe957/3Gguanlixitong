//
//  SuperView.h
//  手动布局视图
//
//  Created by 张佳乔 on 2021/6/10.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface SuperView : UIView {
    UIView* _view01;
    UIView* _view02;
    UIView* _view03;
    UIView* _view04;
    UIView* _view05;
}

- (void) createSubViews;

@end

NS_ASSUME_NONNULL_END
