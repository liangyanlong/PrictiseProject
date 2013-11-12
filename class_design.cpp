/*
 * kAbort: 已失效的牌
 * kInOrder: 在手上的牌
 * kSingle: 单牌
 * kOnePair: 一对
 * kTwoPairs: 连续的两对
 * kThreePairs: 连续的三对
 * kStraight: 顺子（大于等于5张连续的牌）
 * kPlane: 飞机（三张相同牌带任意一张单牌）
 * kThreePair: 三张相同牌带任意一对
 * kFourTwoSingle: 四张相同牌带任意两张单牌
 * kFourTwoPairs: 四张相同牌带任意两对
 * kBomb: 炸弹（大于等于四张相同牌）
 * kRock: 火箭（一对王）
 */
enum PokerState{ kAbort, kInOrder, kSingle, kOnePair, kThreePairs, kStraight, kPlane, kThreePair, kFourTwoSingle, kFourTwoPairs, kBomb, kRock};

/*
 * kLord: 地主
 * kPeasent: 农民
 * kOnTure: 出牌阶段
 * kWait: 等待阶段
 */
enum PlayerState{kLord, kPeasent, kOnTure, kWait};

/*
 * struct Poker：
 * 1. 需要存储扑克的逻辑值
 * 2. 需要存贮扑克的中文名称
 * 3. 方便判断出是哪种的牌型
 * 4. 如果不是单牌，方便找出与这张牌相关联的牌组
 * 5. 支持socket传输
 * 6. 支持比较大小
 */
 
struct Poker{
	string name; // 扑克牌的中文名称
	int value; // 扑克牌用于逻辑计算时的值
	PokerState state; // 扑克牌当前的状态
	Poker* pre; // 前一张扑克，如果当前状态为单牌，则该值为空
	Poker* rear; // 后一张扑克，如果当前状态为单牌，则该值为空
};

/*
 * 玩家要有称呼
 * 玩家是否是地主
 * 玩家游戏状态
 * 玩家手上的牌
 * 玩家的各种动作(叫地主、出牌、认输)
 */
class Player{
public:
	bool CallTheLoad(); // 叫地主，返回叫地主是否成功
	bool PokerTure(); // 出牌，返回出牌是否成功
	void GiveUpTheGame(); // 认输
private:
	string name_; // 玩家昵称
	PlayerState state_; // 玩家当前状态（出牌状态|地主状态）
	Poker* first_; // 玩家牌序列的第一张牌
};