#pragma once
#include <unordered_map>
#include"../../../lib/framework.hpp"
#include <iostream>

class Easing
{
private:
	struct Easinginfo
	{
		Easinginfo() = default;
		Easinginfo(float _bigin) {
			count = 0;
			bigin = _bigin;
		}
		float count;
		float bigin;
	};
	static std::unordered_map <float*, Easinginfo>  easinginfo;
public:
	//イージングする関数
	//イージングさせたい変数
	//終わった時になってほしい値
	//どのイージングでしたいのか
	//フレーム数
	static void Start(float& _change,
		float _end, std::function<float(float, float, float)> _easingfunction,
		float _frame = 30) {
		if (easinginfo.find(&_change) == easinginfo.end()) {
			easinginfo[&_change] = Easinginfo(_change);
		}
		if (!End(_change)) {
			easinginfo[&_change].count += 1.f / _frame;
			easinginfo[&_change].count = std::min(1.f, easinginfo[&_change].count);
			_change = _easingfunction(easinginfo[&_change].count, easinginfo[&_change].bigin, _end);
		}
	}
	static bool BiginSet(float& _change) {
		if (End(_change)) {
			easinginfo[&_change].bigin = _change;
			easinginfo[&_change].count = 0;
			return true;
		}
		return false;
	}
	static bool End(float& _change) {
		return easinginfo[&_change].count >= 1;
	}
	static void setUp() {
		for (auto& it : easinginfo)
		{
			if (it.first == nullptr) {
				easinginfo.erase(easinginfo.find(it.first));
			}
		}
		std::cout << easinginfo.size() << std::endl;
	}
	static void clear() {
		easinginfo.clear();
	}

	class Function {
	public:
		static float Linear(float t, float b, float e) {
			return (e - b) * t + b;
		}
		static float BackIn(float t, float b, float e) {
			float s = 1.70158f;
			return (e - b) * t * t * ((s + 1) * t - s) + b;
		}
		static float BackOut(float t, float b, float e) {
			float s = 1.70158f;
			t -= 1.0;
			return (e - b) * (t * t * ((s + 1) * t + s) + 1) + b;
		}
		static float BackInOut(float t, float b, float e) {
			float s = 1.70158f * 1.525f;
			if ((t /= 0.5) < 1) return (e - b) / 2 * (t * t * ((s + 1) * t - s)) + b;
			t -= 2;
			return (e - b) / 2 * (t * t * ((s + 1) * t + s) + 2) + b;
		}
		static float BounceOut(float t, float b, float e) {
			if (t < (1 / 2.75)) {
				return (e - b) * (7.5625 * t * t) + b;
			}
			else if (t < (2.f / 2.75f)) {
				t -= (1.5f/ 2.75f);
				return (e - b) * (7.5625 * t * t + 0.75) + b;
			}
			else if (t < (2.5 / 2.75)) {
				t -= (2.25f / 2.75f);
				return (e - b) * (7.5625 * t * t + 0.9375) + b;
			}
			else {
				t -= (2.625f / 2.75f);
				return (e - b) * (7.5625 * t * t + 0.984375) + b;
			}
		}
		static  float BounceIn(float t, float b, float e) {
			return (e - b) - BounceOut(1.0 - t, 0, e - b) + b;
		}
		static float BounceInOut(float t, float b, float e) {
			if (t < 0.5) return BounceIn(t * 2, 0, e - b) * 0.5 + b;
			else         return BounceOut(t * 2 - 1.0, 0, e - b) * 0.5 + (e - b) * 0.5 + b;
		}
		static float CircIn(float t, float b, float e) {
			return -(e - b) * (std::sqrt(1 - t * t) - 1) + b;
		}
		static float CircOut(float t, float b, float e) {
			t -= 1.0;
			return (e - b) * std::sqrt(1 - t * t) + b;
		}
		static float CircInOut(float t, float b, float e) {
			if ((t /= 0.5) < 1) return -(e - b) / 2 * (std::sqrt(1 - t * t) - 1) + b;
			t -= 2;
			return (e - b) / 2 * (std::sqrt(1 - t * t) + 1) + b;
		}
		static float CubicIn(float t, float b, float e) {
			return (e - b) * t * t * t + b;
		}
		static float CubicOut(float t, float b, float e) {
			t -= 1.0;
			return (e - b) * (t * t * t + 1) + b;
		}
		static float CubicInOut(float t, float b, float e) {
			if ((t /= 0.5) < 1) return (e - b) / 2 * t * t * t + b;
			t -= 2;
			return (e - b) / 2 * (t * t * t + 2) + b;
		}
		static float ElasticIn(float t, float b, float e) {
			if (t == 0) return b;
			if (t == 1) return e;

			float p = 0.3f;
			float a = e - b;
			float s = p / 4;
			t -= 1;
			return -(a * std::pow(2, 10 * t) * std::sin((t - s) * (2 * M_PI) / p)) + b;
		}
		static float ElasticOut(float t, float b, float e) {
			if (t == 0) return b;
			if (t == 1) return e;

			float p = 0.3f;
			float a = e - b;
			float s = p / 4;
			return (a * std::pow(2, -10 * t) * std::sin((t - s) * (2 * M_PI) / p) + a + b);
		}
		static float ElasticInOut(float t, float b, float e) {
			if (t == 0) return b;
			if ((t /= 0.5) == 2) return e;

			float p = 0.3f * 1.5f;
			float a = e - b;
			float s = p / 4;
			if (t < 1) {
				t -= 1;
				return -0.5 * (a * std::pow(2, 10 * t) * std::sin((t - s) * (2 * M_PI) / p)) + b;
			}
			t -= 1;
			return a * std::pow(2, -10 * t) * std::sin((t - s) * (2 * M_PI) / p) * 0.5 + a + b;
		}
		static float ExpoIn(float t, float b, float e) {
			return (t == 0) ? b : (e - b) * std::pow(2, 10 * (t - 1)) + b;
		}
		static float ExpoOut(float t, float b, float e) {
			return (t == 1) ? e : (e - b) * (-std::pow(2, -10 * t) + 1) + b;
		}
		static float ExpoInOut(float t, float b, float e) {
			if (t == 0) return b;
			if (t == 1) return e;
			if ((t /= 0.5) < 1) return (e - b) / 2 * std::pow(2, 10 * (t - 1)) + b;
			return (e - b) / 2 * (-std::pow(2, -10 * --t) + 2) + b;
		}
		static float QuadIn(float t, float b, float e) {
			return (e - b) * t * t + b;
		}
		static float QuadOut(float t, float b, float e) {
			return -(e - b) * t * (t - 2) + b;
		}
		static float QuadInOut(float t, float b, float e) {
			if ((t /= 0.5) < 1) return (e - b) / 2 * t * t + b;
			--t;
			return -(e - b) / 2 * (t * (t - 2) - 1) + b;
		}
		static float QuartIn(float t, float b, float e) {
			return (e - b) * t * t * t * t + b;
		}
		static float QuartOut(float t, float b, float e) {
			t -= 1.0;
			return -(e - b) * (t * t * t * t - 1) + b;
		}
		static float QuartInOut(float t, float b, float e) {
			if ((t /= 0.5) < 1) return (e - b) / 2 * t * t * t * t + b;
			t -= 2;
			return -(e - b) / 2 * (t * t * t * t - 2) + b;
		}
		static float QuintIn(float t, float b, float e) {
			return (e - b) * t * t * t * t * t + b;
		}
		static float QuintOut(float t, float b, float e) {
			t -= 1.0;
			return (e - b) * (t * t * t * t * t + 1) + b;
		}
		static float QuintInOut(float t, float b, float e) {
			if ((t /= 0.5) < 1) return (e - b) / 2 * t * t * t * t * t + b;
			t -= 2;
			return (e - b) / 2 * (t * t * t * t * t + 2) + b;
		}
		static float SineIn(float t, float b, float e) {
			return -(e - b) * std::cos(t * (M_PI / 2)) + (e - b) + b;
		}
		static float SineOut(float t, float b, float e) {
			return (e - b) * std::sin(t * (M_PI / 2)) + b;
		}
		static float SineInOut(float t, float b, float e) {
			return -(e - b) / 2 * (std::cos(M_PI * t) - 1) + b;
		}
	};
};

