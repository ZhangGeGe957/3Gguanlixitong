//
//  SuperView.m
//  手动布局视图
//
//  Created by 张佳乔 on 2021/6/10.
//

#import "SuperView.h"

@implementation SuperView

- (void) createSubViews {
    //左上角视图
    _view01 = [[UIView alloc] init];
    _view01.frame = CGRectMake(0, 0, self.bounds.size.width / 10, self.bounds.size.height / 10);
    _view01.backgroundColor = [UIColor orangeColor];
    [self addSubview:_view01];
    
    //右上角视图
    _view02 = [[UIView alloc] init];
    _view02.frame = CGRectMake(self.bounds.size.width - self.bounds.size.width / 10, 0, self.bounds.size.width / 10, self.bounds.size.height / 10);
    _view02.backgroundColor = [UIColor orangeColor];
    [self addSubview:_view02];
    
    //右下角视图
    _view03 = [[UIView alloc] init];
    _view03.frame = CGRectMake(self.bounds.size.width - self.bounds.size.width / 10, self.bounds.size.height - self.bounds.size.height / 10, self.bounds.size.width / 10, self.bounds.size.height / 10);
    _view03.backgroundColor = [UIColor orangeColor];
    [self addSubview:_view03];
    
    //左下角视图
    _view04 = [[UIView alloc] init];
    _view04.frame = CGRectMake(0, self.bounds.size.height - self.bounds.size.height / 10, self.bounds.size.width / 10, self.bounds.size.height / 10);
    _view04.backgroundColor = [UIColor orangeColor];
    [self addSubview:_view04];
    
    //中间视图
    _view05 = [[UIView alloc] init];
    _view05.frame = CGRectMake(0, self.bounds.size.height / 2 - 20, self.bounds.size.width, self.bounds.size.height / 10);
    _view05.backgroundColor = [UIColor orangeColor];
    [self addSubview:_view05];
    
    
}

//当需要重新布局时调用此函数
- (void) layoutSubviews {
    
    //无动画效果的缩放
//    _view01.frame = CGRectMake(0, 0, 40, 40);
//    _view02.frame = CGRectMake(self.bounds.size.width - 40, 0, 40, 40);
//    _view03.frame = CGRectMake(self.bounds.size.width - 40, self.bounds.size.height - 40, 40, 40);
//    _view04.frame = CGRectMake(0, self.bounds.size.height - 40, 40, 40);
    
    
    //有动画效果的缩放
    [UIView animateWithDuration:0.5 animations:^{
        self->_view01.frame = CGRectMake(0, 0, self.bounds.size.width / 10, self.bounds.size.height / 10);
        self->_view02.frame = CGRectMake(self.bounds.size.width - self.bounds.size.width / 10, 0, self.bounds.size.width / 10, self.bounds.size.height / 10);
        self->_view03.frame = CGRectMake(self.bounds.size.width - self.bounds.size.width / 10, self.bounds.size.height - self.bounds.size.height / 10, self.bounds.size.width / 10, self.bounds.size.height / 10);
        self->_view04.frame = CGRectMake(0, self.bounds.size.height - self.bounds.size.height / 10, self.bounds.size.width / 10, self.bounds.size.height / 10);
        self->_view05.frame = CGRectMake(0, self.bounds.size.height / 2 - 20, self.bounds.size.width, self.bounds.size.height / 10);
    }];
    
}

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

@end
