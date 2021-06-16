//
//  ViewController.h
//  UITableView
//
//  Created by 张佳乔 on 2021/6/14.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController
<
//实现数据视图的普通协议
//实现视图的普通事件处理
UITableViewDelegate,
//实现数据视图的数据代理协议
//处理数据视图的数据代理
UITableViewDataSource
>
{
    //定义一个数据视图对象
    //数据视图用来显示大量相同格式的信息视图
    //例如：电话通讯录，QQ好友，朋友圈信息等
    UITableView* _tableView;
}


@end

