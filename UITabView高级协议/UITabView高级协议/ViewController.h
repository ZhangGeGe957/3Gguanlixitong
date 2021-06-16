//
//  ViewController.h
//  UITabView高级协议
//
//  Created by 张佳乔 on 2021/6/14.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController
<UITabBarDelegate,
UITableViewDataSource>
{
    //数据视图
    UITableView* _tableView;
    
    //数据源
    NSMutableArray* _arrayData;
    
    //添加导航按钮
    UIBarButtonItem* _buttonEdit;
    UIBarButtonItem* _buttonFinish;
    UIBarButtonItem* _buttonDelete;
    
    //设置编辑状态
    BOOL _isEdit;
}

@end

